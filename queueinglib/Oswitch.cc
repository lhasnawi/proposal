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

#include "Oswitch.h"

namespace queueing {

Define_Module(Oswitch);

extern void *myPtr;

Oswitch::Oswitch() {
    // TODO Auto-generated constructor stub

}

Oswitch::~Oswitch() {
    // TODO Auto-generated destructor stub

    delete cont;


}

ContFrame * Oswitch::genrateCont()
{
    //ContFrame *
    cont = new ContFrame();
    return cont;


}

void Oswitch::switchToCross()
{
    barState = false;
}

void Oswitch::switchToBar()
{
    barState = true;
}

bool Oswitch::getSwitchState()
{
    return barState;
}


void Oswitch::initialize()
{


    WATCH(this->startHolding);
    WATCH(this->releaseTime);
    WATCH(this->guardTime);
    WATCH(this->barState);
    Oswitch::switchToBar();


}

double Oswitch::getDataRate() const {
    return dataRate;
}

void Oswitch::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Oswitch::getGuardTime() const {
    return guardTime;
}

void Oswitch::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
}

int Oswitch::getNumFrames() const {
    return numFrames;
}

void Oswitch::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Oswitch::getNumTimeslots() const {
    return numTimeslots;
}

void Oswitch::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

simtime_t Oswitch::getTimeslotDuration()  {
    return timeslotDuration;
}

void Oswitch::setTimeslotDuration(simtime_t timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int Oswitch::getTimeslotSize() const {
    return timeslotSize;
}

void Oswitch::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

const simtime_t& Oswitch::getReleaseTime() const {
    return releaseTime;
}

void Oswitch::setReleaseTime(const simtime_t& releaseTime) {
    this->releaseTime = releaseTime;
}

const simtime_t& Oswitch::getStartHolding() const {
    return startHolding;
}

void Oswitch::setStartHolding(const simtime_t& startHolding) {
    this->startHolding = startHolding;
}

void Oswitch::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Oswitch::setNumTimeslots(PC->getNumTimeslots());
        Oswitch::setNumFrames(PC->getNumFrames());
        Oswitch::setTimeslotSize(PC->getTimeslotSize());
        Oswitch::setDataRate(PC->getDataRate());
        Oswitch::setTimeslotDuration(PC->getTimeslotDuration());
        Oswitch::setGuardTime(PC->getGuardTime());

        delete msg;

        ContFrame *oswitchCont = Oswitch::genrateCont();

        oswitchCont->setModuleName(this->getName());
        oswitchCont->setModuleID(this->getId());
        oswitchCont->setModuleType(4);// module 4 -> switch
        oswitchCont->setKind(0);

        if (myPtr != NULL)
        {
            myCtl = (Ocontroller*)myPtr;

        }
        else
        {
            myCtl = NULL;
            cout<<"ERROR Controller Pointer @ Switch"<<endl;
        }

        send(oswitchCont,"control$o");
        //delete msg;



    }
    else if (strcmp(msg->getName(),"releaseMessage")==0)
        {
            //Message to release switching state
        Oswitch::switchToBar();
        Oswitch::setModuleBusyStateTo(this->getName(), 1);
         bubble ("StateReleased");
         EV<<"Module "<<this->getName()<<" released its state available state "<<Oswitch::getModuleBusyStateTo(this->getName())<<endl;
         cancelAndDelete (releaseMessage);

        }

    else if (strcmp(msg->getClassName(),"queueing::SwitchingCont")==0)        // it is control Packet
    {
        //Control Message
        SwitchingCont * cont = check_and_cast<SwitchingCont *>(msg);
        barState = cont->getSwitchingState();
        startHolding = cont->getStartHoldingTime();
        releaseTime =cont->getArrivalTime()+Oswitch::getTimeslotDuration()*.9;
        releaseMessage = new cMessage();
        releaseMessage->setName("releaseMessage");
        EV<<"Message Arrival Time = "<<cont->getArrivalTime()<<" TSD = "<<Oswitch::getTimeslotDuration()<<" Release Time = "<<releaseTime<<endl;
        scheduleAt(releaseTime, releaseMessage);
        delete msg;


    }

    else if (strcmp(msg->getClassName(),"queueing::Oframe")==0)
    {

                if (ev.isGUI())
                getDisplayString().setTagArg("i",1, "cyan3");
                // Data Message
            switch (Oswitch::getSwitchState())
            {
            case true:
            {

                if (msg->getArrivalGate()==Oswitch::gate("in",0))
                {
                    send(msg,Oswitch::gate("out",0));
                    //scheduleAt(releaseSwitchingState);
                   // Oswitch::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                else
                {
                    send(msg,Oswitch::gate("out",1));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                  //  Oswitch::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                break;
            }
            case false:
            {
                if (msg->getArrivalGate()==Oswitch::gate("in",0))
                {
                    send(msg,Oswitch::gate("out",1));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                   // Oswitch::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                else
                {
                    send(msg,Oswitch::gate("out",0));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                   // Oswitch::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                break;
            }//end of case false
            }// end of switch statement


    }//end Else Oframe



}//end handleMessage

void Oswitch::setModuleBusyStateTo(string moduleName, bool availableState)
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
                       Oswitch::switchToBar();
                       //delete SWC;
                      // bubble ("StateReleased");
                   }
                   else
                   {
                       itt->setBusy();
                       cout<<"I am busy"<<endl;

                   }

                   }// end of IF moduleType
               }}


        bool Oswitch::getModuleBusyStateTo(string moduleName)
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
