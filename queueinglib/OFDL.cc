//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "OFDL.h"


namespace queueing {

Define_Module(OFDL);

extern void *myPtr;

OFDL::OFDL()
{
    frmServiced = NULL;
    endServiceMsg = NULL;

}

OFDL::~OFDL()
{
    //delete frmServiced;
    cancelAndDelete(endServiceMsg);


}

double OFDL::getDataRate() const {
    return dataRate;
}

void OFDL::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double OFDL::getGuardTime() const {
    return guardTime;
}

void OFDL::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
}

int OFDL::getNumFrames() const {
    return numFrames;
}

void OFDL::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int OFDL::getNumTimeslots() const {
    return numTimeslots;
}

void OFDL::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

double OFDL::getTimeslotDuration() const {
    return timeslotDuration;
}

void OFDL::setTimeslotDuration(double timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int OFDL::getTimeslotSize() const {
    return timeslotSize;
}

void OFDL::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

double OFDL::getServiceTime() const {
    return serviceTime;
}

void OFDL::setServiceTime(double serviceTime) {
    this->serviceTime = serviceTime;
}

ContFrame * OFDL::genrateCont()
{
    ContFrame * cont = new ContFrame();
    return cont;

}

void OFDL::initialize()
{

   /* droppedSignal = registerSignal("dropped");
    queueingTimeSignal = registerSignal("queueingTime");
    queueLengthSignal = registerSignal("queueLength");
    emit(queueLengthSignal, 0);
    busySignal = registerSignal("busy");
    emit(busySignal, 0);*/
    WATCH(this->guardTime);

    endServiceMsg = new cMessage("end-service");
    fifo = par("fifo");
    capacity = par("capacity");
    queue.setName("queue");

}

void OFDL::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        OFDL::setNumTimeslots(PC->getNumTimeslots());
        OFDL::setNumFrames(PC->getNumFrames());
        OFDL::setTimeslotSize(PC->getTimeslotSize());
        OFDL::setDataRate(PC->getDataRate());
        OFDL::setTimeslotDuration(PC->getTimeslotDuration());
        OFDL::setGuardTime(PC->getGuardTime());
        OFDL::setServiceTime(PC->getTimeslotDuration()*.99);

        delete msg;

        ContFrame *ofdlCont = OFDL::genrateCont();

        ofdlCont->setModuleName(this->getName());
        ofdlCont->setModuleID(this->getId());
        ofdlCont->setModuleType(3);// module 3 -> OFDL
        ofdlCont->setKind(0);

        if (myPtr != NULL)
        {
            myCtl = (Ocontroller*)myPtr;

        }
        else
        {
            myCtl = NULL;
            cout<<"ERROR Controller Pointer @ OFDL"<<endl;
        }

        send(ofdlCont,"control$o");


    }

    else if (msg==endServiceMsg)
    {
        endService( frmServiced );
        if (queue.empty())
        {
            frmServiced = NULL;
           // emit(busySignal, 0);
        }
        else
        {
            frmServiced = getFromQueue();
           // emit(queueLengthSignal, length());
            simtime_t serviceTime = startService( frmServiced );
            scheduleAt( simTime()+serviceTime, endServiceMsg );
        }
    }

    else if (strcmp(msg->getClassName(),"queueing::Oframe")==0)
    {

        Oframe *frm = check_and_cast<Oframe *>(msg);
        if (frm->getFrameDelayed()==false)
        {
            int currentFrameIndex = frm->getNewFrameIndex();
            frm->setNewFrameIndex(currentFrameIndex+1);
            frm->setFrameDelayed(true);
            if (frm->getNewFrameIndex()>=OFDL::getNumFrames())
            {
                frm->setNewFrameIndex(0);
            }

        }
        int currentTimeslotIndex = frm->getNewTimeslotIndex();
        frm->setNewTimeslotIndex(currentTimeslotIndex+1);
        if (frm->getNewTimeslotIndex()==OFDL::getNumTimeslots())
        {
            frm->setNewTimeslotIndex(0);
        }

        arrival(frm);

        if (!frmServiced)
        {
        // processor was idle

            frmServiced = frm;
           // emit(busySignal, 1);
            simtime_t serviceTime = startService( frmServiced );
            scheduleAt( simTime()+serviceTime, endServiceMsg );

        }
        else
        {
            // check for container capacity
            if (capacity >=0 && queue.length() >= capacity)
            {
                EV << "Capacity full! Job dropped.\n";
                if (ev.isGUI()) bubble("Dropped!");
              //  emit(droppedSignal, 1);
                 delete frm; // do not know what is this
                return;
            }
            queue.insert( frm );
          //  emit(queueLengthSignal, length());
             //frm->get     job->setQueueCount(job->getQueueCount() + 1);
        }
    }
    if (ev.isGUI())
    getDisplayString().setTagArg("i",1,!frmServiced ? "" :"cyan3");


}

Oframe *OFDL::getFromQueue()
{
    Oframe *frm = (Oframe *)queue.pop();
    return frm;
}

int OFDL::length()
{
    return queue.length();
}

void OFDL::arrival(Oframe *frm)
{
    frm->setTimestamp();
}

simtime_t OFDL::startService(Oframe *frm)
{
    // gather queueing time statistics
    simtime_t d = simTime() - frm->getTimestamp();
   // emit(queueingTimeSignal, d);
    //job->setTotalQueueingTime(job->getTotalQueueingTime() + d);
    EV << "Starting service of Frame # " << frm->getFrameIndex()<<" Timeslot # "<<frm->getTimeslotIndex() <<"at time " <<simTime()<<endl;
    frm->setTimestamp();
    return OFDL::getServiceTime();
}

void OFDL::endService(Oframe *frm)
{
    EV << "Ending service of Frame # " << frm->getFrameIndex()<<" Timeslot # "<<frm->getTimeslotIndex() << "at time " <<simTime()<<endl;
    simtime_t d = simTime() - frm->getTimestamp();
    frm->setDelayCount(frm->getDelayCount()+1);
    //job->setTotalServiceTime(job->getTotalServiceTime() + d);
    send(frm, "out");
    //getDisplayString().setTagArg("i",2, "grey");
    OFDL::setModuleBusyStateTo(this->getName(),1);
}

void OFDL::finish()
{
}

void OFDL::setModuleBusyStateTo(string moduleName, bool availableState)
{
        list<ModuleInfo>::iterator itt;
        list<ModuleInfo>::iterator iStart = myCtl->modules.begin();
        list<ModuleInfo>::iterator iEnd = myCtl->modules.end();

        for (itt = iStart ; itt != iEnd ; ++itt)
           {
               if ( itt->getModuleName()==moduleName)
                   {
                   if (availableState == true)
                   {
                       itt->setFree();
                       bubble("Available now");
                   }
                   else
                   {
                       itt->setBusy();
                       EV<<"I am busy"<<endl;
                   }
                   }// end of IF moduleType
           }
}

}; //namespace

