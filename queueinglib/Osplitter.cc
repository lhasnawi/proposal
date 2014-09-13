//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Osplitter.h"

namespace queueing {


Define_Module(Osplitter);

extern void *myPtr;

Osplitter::Osplitter() {

}

Osplitter::~Osplitter() {
    // TODO Auto-generated destructor stub
    //delete myCtl;
    //delete cont;

}

ContFrame * Osplitter::genrateCont()
{
    ContFrame *cont = new ContFrame();
    return cont;
}

void Osplitter::switchToCross()
{
    barState = false;
}

void Osplitter::switchToBar()
{
    barState = true;
}

bool Osplitter::getSwitchState()
{
    return barState;
}

void Osplitter::initialize()
{

    arrivalSignal = registerSignal("arrival");

    WATCH(this->startHolding);
    WATCH(this->releaseTime);
    WATCH(this->guardTime);
    WATCH(this->barState);
    WATCH(this->moduleUsed);
    Osplitter::switchToBar();
    moduleUsed = false;
    this->arrivaleCount=0;

}

double Osplitter::getDataRate() const {
    return dataRate;
}

void Osplitter::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Osplitter::getGuardTime() const {
    return guardTime;
}

void Osplitter::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
}

int Osplitter::getNumFrames() const {
    return numFrames;
}

void Osplitter::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Osplitter::getNumTimeslots() const {
    return numTimeslots;
}

void Osplitter::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

double Osplitter::getTimeslotDuration() const {
    return timeslotDuration;
}

void Osplitter::setTimeslotDuration(double timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int Osplitter::getTimeslotSize() const {
    return timeslotSize;
}

void Osplitter::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

void Osplitter::setModuleBusyStateTo(string moduleName, bool availableState)
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
                       Osplitter::switchToBar();
                       //bubble ("StateReleased");
                   }
                   else
                   {
                       itt->setBusy();
                       cout<<"I am busy"<<endl;

                   }

                   }// end of IF moduleType
           }


}

bool Osplitter::getModuleBusyStateTo(string moduleName)
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

const simtime_t& Osplitter::getReleaseTime() const {
    return releaseTime;
}

void Osplitter::setReleaseTime(const simtime_t& releaseTime) {
    this->releaseTime = releaseTime;
}

const simtime_t& Osplitter::getStartHolding() const {
    return startHolding;
}

void Osplitter::setStartHolding(const simtime_t& startHolding) {
    this->startHolding = startHolding;
}

void Osplitter::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Osplitter::setNumTimeslots(PC->getNumTimeslots());
        Osplitter::setNumFrames(PC->getNumFrames());
        Osplitter::setTimeslotSize(PC->getTimeslotSize());
        Osplitter::setDataRate(PC->getDataRate());
        Osplitter::setTimeslotDuration(PC->getTimeslotDuration());
        Osplitter::setGuardTime(PC->getGuardTime());

        //delete PC;
        delete msg;


        ContFrame *osplitterCont = Osplitter::genrateCont();

        osplitterCont->setModuleName(this->getName());
        osplitterCont->setModuleID(this->getId());
        osplitterCont->setModuleType(5);// module 5 -> splitter
        osplitterCont->setKind(0);

        if (myPtr != NULL)
        {

            myCtl = (Ocontroller*)myPtr;

        }
        else
        {
            myCtl = NULL;
            cout<<"ERROR Controller Pointer @ Splitter"<<endl;
        }



        send(osplitterCont,"control$o");
        //delete PC;

    }
    else if (strcmp(msg->getName(),"releaseMessage")==0)
    {
        //Message to release switching state
       Osplitter::switchToBar();
       Osplitter::setModuleBusyStateTo(this->getName(), 1);
        bubble ("StateReleased");
        EV<<"Module "<<this->getName()<<" released its state available state "<<Osplitter::getModuleBusyStateTo(this->getName())<<endl;
        cancelAndDelete (releaseMessage);



    }

    else if (strcmp(msg->getClassName(),"queueing::SwitchingCont")==0)       // it is control Packet
    {
        //Control Message
        SwitchingCont * cont = check_and_cast<SwitchingCont *>(msg);

        barState = cont->getSwitchingState();
        startHolding = cont->getStartHoldingTime();
        releaseTime =cont->getArrivalTime()+Osplitter::getTimeslotDuration()*.9;
        releaseMessage = new cMessage();
        releaseMessage->setName("releaseMessage");
        EV<<"Message Arrival Time = "<<cont->getArrivalTime()<<" TSD = "<<Osplitter::getTimeslotDuration()<<" Release Time = "<<releaseTime<<endl;
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
                switch (Osplitter::getSwitchState())
                {
                    case true:
                    {
                        send(msg,Osplitter::gate("out",0));
                        this->arrivaleCount++;
                        //emit(arrivalSignal,1);
                        //Osplitter::setModuleBusyStateTo(this->getName(),1);
                        if (ev.isGUI())
                                   getDisplayString().setTagArg("i",2, "grey");
                        break;
                    }
                    case false:
                    {
                        send(msg,Osplitter::gate("out",1));
                        //Osplitter::setModuleBusyStateTo(this->getName(),1);
                        this->arrivaleCount++;
                       // emit(arrivalSignal,1);
                        getDisplayString().setTagArg("i",2, "grey");

                        break;
                    }
                    default:
                        break;

                }//end of switch
    }//end Else



}//end handleMessage

void Osplitter::finish()
{
    emit(arrivalSignal, arrivaleCount);

}


} /* namespace queueing */
