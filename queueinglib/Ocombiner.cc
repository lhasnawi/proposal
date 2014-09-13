
#include "Ocombiner.h"

namespace queueing
{

Define_Module(Ocombiner);

extern void *myPtr;

Ocombiner::Ocombiner()
{

    this->moduleUsed = false;

}

Ocombiner::~Ocombiner()
{
    // TODO Auto-generated destructor stub

    //delete myCtl;
}

ContFrame * Ocombiner::genrateCont()
{
    ContFrame *cont = new ContFrame();
    return cont;

}

void Ocombiner::switchToCross()
{
    barState = false;
}

void Ocombiner::switchToBar()
{
    barState = true;
}

bool Ocombiner::getSwitchState()
{
    return barState;
}

void Ocombiner::initialize()
{

    WATCH(this->startHolding);
    WATCH(this->releaseTime);
    WATCH(this->guardTime);
    WATCH(this->barState);
    WATCH(this->moduleUsed);
    Ocombiner::setReleaseTime(0);
    this->droppedTS=0;
    WATCH(droppedTS);



}

double Ocombiner::getDataRate() const
{
    return dataRate;
}

void Ocombiner::setDataRate(double dataRate)
{
    this->dataRate = dataRate;
}

double Ocombiner::getGuardTime() const
{
    return guardTime;
}

void Ocombiner::setGuardTime(double guardTime)
{
    this->guardTime = guardTime;
}

int Ocombiner::getNumFrames() const
{
    return numFrames;
}

void Ocombiner::setNumFrames(int numFrames)
{
    this->numFrames = numFrames;
}

int Ocombiner::getNumTimeslots() const
{
    return numTimeslots;
}

void Ocombiner::setNumTimeslots(int numTimeslots)
{
    this->numTimeslots = numTimeslots;
}

simtime_t Ocombiner::getTimeslotDuration()
{
    return timeslotDuration;
}

void Ocombiner::setTimeslotDuration(simtime_t timeslotDuration)
{
    this->timeslotDuration = timeslotDuration;
}

int Ocombiner::getTimeslotSize() const
{
    return timeslotSize;
}

void Ocombiner::setTimeslotSize(int timeslotSize)
{
    this->timeslotSize = timeslotSize;
}

const simtime_t& Ocombiner::getReleaseTime() const
{
    return releaseTime;
}

void Ocombiner::setReleaseTime(const simtime_t& releaseTime)
{
    this->releaseTime = releaseTime;
}

const simtime_t& Ocombiner::getStartHolding() const
{
    return startHolding;
}

void Ocombiner::setStartHolding(const simtime_t& startHolding)
{
    this->startHolding = startHolding;
}

void Ocombiner::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"releaseMessage")==0)
    {
        //Message to release switching state
        Ocombiner::switchToBar();
        Ocombiner::setModuleBusyStateTo(this->getName(), 1);
        bubble ("StateReleased");
        EV<<"Module "<<this->getName()<<" released its state available state "<<Ocombiner::getModuleBusyStateTo(this->getName())<<endl;
        cancelAndDelete(releaseMessage);
    }

    else if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Ocombiner::setNumTimeslots(PC->getNumTimeslots());
        Ocombiner::setNumFrames(PC->getNumFrames());
        Ocombiner::setTimeslotSize(PC->getTimeslotSize());
        Ocombiner::setDataRate(PC->getDataRate());
        Ocombiner::setTimeslotDuration(PC->getTimeslotDuration());
        Ocombiner::setGuardTime(PC->getGuardTime());
        delete msg;

        ContFrame *ocombinerCont = Ocombiner::genrateCont();

        ocombinerCont->setModuleName(this->getName());
        ocombinerCont->setModuleID(this->getId());
        ocombinerCont->setModuleType(6);// module 6 -> combiner
        ocombinerCont->setKind(0);

        if (myPtr != NULL)
        {
            myCtl = (Ocontroller*)myPtr;

        }
        else
        {
            myCtl = NULL;
            cout<<"ERROR Controller Pointer @ Combiner"<<endl;
        }

        send(ocombinerCont,"control$o");



    }

    else if (strcmp(msg->getClassName(),"queueing::SwitchingCont")==0)        // it is control Packet
    {
        //Control Message
        SwitchingCont * cont = check_and_cast<SwitchingCont *>(msg);

        barState = cont->getSwitchingState();
        releaseTime =cont->getArrivalTime()+Ocombiner::getTimeslotDuration()*.9;
        releaseMessage = new cMessage();
        releaseMessage->setName("releaseMessage");
        EV<<"Message Arrival Time = "<<cont->getArrivalTime()<<" TSD = "<<Ocombiner::getTimeslotDuration()<<" Release Time = "<<releaseTime<<endl;
        scheduleAt(releaseTime, releaseMessage);
        delete msg;

    }

    else if (strcmp(msg->getClassName(),"queueing::Oframe")==0)
    {
        if (moduleUsed == false)
        {
            moduleUsed = true;
        }

        //Data Message
        if (ev.isGUI())
        getDisplayString().setTagArg("i",1, "cyan3");
        if(this->barState==true)
        {
            // Set to Bar
            if(msg->arrivedOn("in",0))
            {
                // Arrived at the right state
                send(msg,Ocombiner::gate("out"));
               // Ocombiner::setModuleBusyStateTo(this->getName(), 1);
                if (ev.isGUI())
                           getDisplayString().setTagArg("i",2, "grey");
            }
            else
            {
                   // Arrived at wrong State
                bubble ("Arrived at wrong State & blocked");
                this->droppedTS++;
            }
        }
        else
        {
            // Set to Cross
            if(msg->arrivedOn("in",1))
            {
                // Arrived at the right state
                send(msg,Ocombiner::gate("out"));
               // Ocombiner::setModuleBusyStateTo(this->getName(), 1);
                if (ev.isGUI())
                           getDisplayString().setTagArg("i",2, "grey");
            }
            else
            {
                   // Arrived at wrong State
                bubble ("Arrived at wrong State & blocked");
                this->droppedTS++;
            }

        }


    }



}//end handleMessage

void Ocombiner::setModuleBusyStateTo(string moduleName, bool availableState)
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
                       Ocombiner::switchToBar();
                      // bubble ("StateReleased");
                   }
                   else
                   {
                       itt->setBusy();
                       cout<<"I am busy"<<endl;

                   }

                   }// end of IF moduleType
           }


}
bool Ocombiner::getModuleBusyStateTo(string moduleName)
{
    bool currentState;

        list<ModuleInfo>::iterator itt;
        list<ModuleInfo>::iterator iStart = myCtl->modules.begin();
        list<ModuleInfo>::iterator iEnd = myCtl->modules.end();

        for (itt = iStart ; itt != iEnd ; ++itt)
           {
               if ( itt->getModuleName()==moduleName)
                   {
                       currentState = itt->isBusy();


                   }// end of IF moduleType
           }
        return currentState;


}
} /* namespace queueing */
