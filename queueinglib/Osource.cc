//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#include "Osource.h"


namespace queueing {

void *srcPtr = NULL;



Define_Module(Osource);

Oframe * Osource::generateFrame()
{

    if (Osource::getTimeslotCounter()==0 && Osource::getFrameCounter()==0)
    {
        // Create Oframe object
                    //Oframe *
                    frm = new Oframe();
                    frm->setFrameIndex(Osource::getFrameCounter());
                    frm->setTimeslotIndex(Osource::getTimeslotCounter());
                    frm->setBitLength(Osource::getTimeslotSize());
                    frm->setFrameDelayed(false);
                    frm->setDelayCount(0);
                    Osource::increaseTimeslotCounter();
                    frm->setKind(4);
                    return frm;

    }
    else if (timeslotCounter>=Osource::getNumTimeslots())
        {

            Osource::setTimeslotCounter();
            //Osource::increaseFrameCounter();

            // Create Oframe object
            //Oframe *
            frm = new Oframe();
            frm->setFrameIndex(Osource::getFrameCounter());
            frm->setTimeslotIndex(Osource::getTimeslotCounter());
            frm->setBitLength(Osource::getTimeslotSize());
            frm->setFrameDelayed(false);
            frm->setDelayCount(0);
            Osource::increaseTimeslotCounter();
            frm->setKind(4);
            return frm;

        }
    else
        {


            // Create Oframe object
            //Oframe *
            frm = new Oframe();
            frm->setFrameIndex(Osource::getFrameCounter());
            frm->setTimeslotIndex(Osource::getTimeslotCounter());
            frm->setBitLength(Osource::getTimeslotSize());
            frm->setFrameDelayed(false);
            frm->setNewTimeslotIndex(Osource::getTimeslotCounter());
            frm->setNewFrameIndex(Osource::getFrameCounter());
            frm->setDelayCount(0);
            Osource::increaseTimeslotCounter();
            frm->setKind(4);
            return frm;


        }

}

ContFrame * Osource::genrateCont()
{
   // ContFrame *
    cont = new ContFrame();
    return cont;


}

/*SyncFrame * Osource::generateSyncFrame()
{
    SyncFrame * syncFrm = new SyncFrame();
    return syncFrm;
}*/

Osource::Osource()
{
    Osource::setTimeslotCounter();
    Osource::setFrameCounter();
    srcPtr = this;

}

Osource::~Osource()
{
    cancelAndDelete(osourceEvent);
    delete frm;
    delete cont;


}

void Osource::initialize()
{

    createdSignal = registerSignal("created");
    jobCounter = 0;
    WATCH(jobCounter);
    WATCH(InterArrivalTime);
    WATCH(timeslotSize);
    WATCH(timeslotDuration);
    WATCH(guardTime);
    this->frameCounter = 0;
    this->timeslotCounter = 0;

    startTime = par("startTime");
    stopTime = par("stopTime");
    numJobs = par("numJobs");

    //Schedule the First Message for sync
    osourceEvent = new cMessage();
    osourceEvent->setName("osourceEvent");
    osourceEvent->setKind(3);







}

void Osource::handleMessage(cMessage *msg)
{
    //ASSERT(msg->isSelfMessage());

    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Osource::setNumTimeslots(PC->getNumTimeslots());
        Osource::setNumFrames(PC->getNumFrames());
        Osource::setTimeslotSize(PC->getTimeslotSize());
        Osource::setDataRate(PC->getDataRate());
        Osource::setTimeslotDuration(PC->getTimeslotDuration());
        Osource::setGuardTime(PC->getGuardTime());
        Osource::setInterArrivalTime();
        this->numJobs=Osource::getNumFrames()*Osource::getNumTimeslots();
        delete msg;

        ContFrame *osourceCont = Osource::genrateCont();

        osourceCont->setModuleName(this->getName());
        osourceCont->setModuleID(this->getId());
        osourceCont->setModuleType(0);// module 0 -> source
        osourceCont->setKind(0);

        send(osourceCont,"control$o");
        scheduleAt(1+Osource::getGuardTime(), osourceEvent);

    }




    else if (strcmp(msg->getName(),"osourceEvent")==0) //&& (stopTime < 0 || stopTime > simTime()))
    {
        if (numJobs < 0 || numJobs > jobCounter)
        {

          // reschedule the timer for the next message
          scheduleAt(simTime()+Osource::getTimeslotDuration(), osourceEvent);

          Oframe *frm = generateFrame();
          Osource::increaseJobCounter();


          send(frm, "out");
        }
        else
        {
            Osource::finish();
        }


    }
    else
    {
        // finished
    }// end else
}//end handle

void Osource::finish()
{
    emit(createdSignal, jobCounter);

}

        //Setters

void Osource::setFrameCounter()
{
    frameCounter = 0;
}

void Osource::setTimeslotCounter()
{
    timeslotCounter =0;
}



double Osource::getInterArrivalTime()
{
    return InterArrivalTime;
}

void Osource::setInterArrivalTime()
{
    InterArrivalTime = Osource::getTimeslotDuration()+Osource::getGuardTime();
}

void Osource::setJobCounter(int jobCounter)
{
    this->jobCounter = jobCounter;
}



        //Getters



int Osource::getFrameCounter()
{
    return frameCounter;
}

int Osource::getTimeslotCounter()
{
    return timeslotCounter;
}

int Osource::getJobCounter() const
{
    return jobCounter;
}



void Osource::increaseFrameCounter()
{
    if (Osource::getFrameCounter()<Osource::getNumFrames()-1)
     this->frameCounter++;
    else
        Osource::setFrameCounter();
}

void Osource::increaseTimeslotCounter()
{

    if (Osource::getTimeslotCounter()<Osource::getNumTimeslots()-1)
        this->timeslotCounter++;
    else
    {
        Osource::setTimeslotCounter();
        Osource::increaseFrameCounter();
    }

}

double Osource::getDataRate()  {
    return dataRate;
}

void Osource::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Osource::getGuardTime()  {
    return guardTime;
}

void Osource::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
    Osource::setInterArrivalTime();
}

int Osource::getNumFrames()  {
    return numFrames;
}

void Osource::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Osource::getNumTimeslots()  {
    return numTimeslots;
}

void Osource::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

double Osource::getTimeslotDuration()  {
    return timeslotDuration;
}

void Osource::setTimeslotDuration(double timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int Osource::getTimeslotSize()  {
    return timeslotSize;
}

int Osource::getNumJobs() const {
    return numJobs;
}

void Osource::setNumJobs(int numJobs) {
    this->numJobs = numJobs;
}

void Osource::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

void Osource::increaseJobCounter()
{

    this->jobCounter++;
}




}; //namespace


