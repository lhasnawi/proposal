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

#include "switch3D.h"

namespace queueing {

Define_Module(Switch3D);


extern void *myPtr3D;

Switch3D::Switch3D() {
    // TODO Auto-generated constructor stub

}

Switch3D::~Switch3D() {
    // TODO Auto-generated destructor stub

    delete cont;


}

ContFrame * Switch3D::genrateCont()
{
    //ContFrame *
    cont = new ContFrame();
    return cont;


}

void Switch3D::switchToCross()
{
    barState = false;
}

void Switch3D::switchToBar()
{
    barState = true;
}

bool Switch3D::getSwitchState()
{
    return barState;
}


void Switch3D::initialize()
{


    WATCH(this->startHolding);
    WATCH(this->releaseTime);
    WATCH(this->guardTime);
    WATCH(this->barState);
    Switch3D::switchToBar();


}

double Switch3D::getDataRate() const {
    return dataRate;
}

void Switch3D::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Switch3D::getGuardTime() const {
    return guardTime;
}

void Switch3D::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
}

int Switch3D::getNumFrames() const {
    return numFrames;
}

void Switch3D::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Switch3D::getNumTimeslots() const {
    return numTimeslots;
}

void Switch3D::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

simtime_t Switch3D::getTimeslotDuration()  {
    return timeslotDuration;
}

void Switch3D::setTimeslotDuration(simtime_t timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int Switch3D::getTimeslotSize() const {
    return timeslotSize;
}

void Switch3D::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

const simtime_t& Switch3D::getReleaseTime() const {
    return releaseTime;
}

void Switch3D::setReleaseTime(const simtime_t& releaseTime) {
    this->releaseTime = releaseTime;
}

const simtime_t& Switch3D::getStartHolding() const {
    return startHolding;
}

void Switch3D::setStartHolding(const simtime_t& startHolding) {
    this->startHolding = startHolding;
}

void Switch3D::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Switch3D::setNumTimeslots(PC->getNumTimeslots());
        Switch3D::setNumFrames(PC->getNumFrames());
        Switch3D::setTimeslotSize(PC->getTimeslotSize());
        Switch3D::setDataRate(PC->getDataRate());
        Switch3D::setTimeslotDuration(PC->getTimeslotDuration());
        Switch3D::setGuardTime(PC->getGuardTime());

        delete msg;

        ContFrame *oswitchCont = Switch3D::genrateCont();

        oswitchCont->setModuleName(this->getName());
        oswitchCont->setModuleID(this->getId());
        oswitchCont->setModuleType(4);// module 4 -> switch
        oswitchCont->setKind(0);

        if (myPtr3D != NULL)
        {
            myCtl = (Controller3D*)myPtr3D;

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
        Switch3D::switchToBar();
        Switch3D::setModuleBusyStateTo(this->getName(), 1);
         bubble ("StateReleased");
         EV<<"Module "<<this->getName()<<" released its state available state "<<Switch3D::getModuleBusyStateTo(this->getName())<<endl;
         cancelAndDelete (releaseMessage);

        }

    else if (strcmp(msg->getClassName(),"queueing::SwitchingCont")==0)        // it is control Packet
    {
        //Control Message
        SwitchingCont * cont = check_and_cast<SwitchingCont *>(msg);
        barState = cont->getSwitchingState();
        startHolding = cont->getStartHoldingTime();
        releaseTime =cont->getArrivalTime()+Switch3D::getTimeslotDuration()*.9;
        releaseMessage = new cMessage();
        releaseMessage->setName("releaseMessage");
        EV<<"Message Arrival Time = "<<cont->getArrivalTime()<<" TSD = "<<Switch3D::getTimeslotDuration()<<" Release Time = "<<releaseTime<<endl;
        scheduleAt(releaseTime, releaseMessage);
        delete msg;


    }

    else if (strcmp(msg->getClassName(),"queueing::Oframe")==0)
    {

                if (ev.isGUI())
                getDisplayString().setTagArg("i",1, "cyan3");
                // Data Message
            switch (Switch3D::getSwitchState())
            {
            case true:
            {

                if (msg->getArrivalGate()==Switch3D::gate("in",0))
                {
                    send(msg,Switch3D::gate("out",0));
                    //scheduleAt(releaseSwitchingState);
                   // Switch3D::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                else
                {
                    send(msg,Switch3D::gate("out",1));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                  //  Switch3D::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                break;
            }
            case false:
            {
                if (msg->getArrivalGate()==Switch3D::gate("in",0))
                {
                    send(msg,Switch3D::gate("out",1));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                   // Switch3D::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                else
                {
                    send(msg,Switch3D::gate("out",0));
                    //scheduleAt(releaseTime,releaseSwitchingState);
                   // Switch3D::setModuleBusyStateTo(this->getName(),1);
                    if (ev.isGUI())
                               getDisplayString().setTagArg("i",2, "grey");
                }
                break;
            }//end of case false
            }// end of switch statement


    }//end Else Oframe



}//end handleMessage

void Switch3D::setModuleBusyStateTo(string moduleName, bool availableState)
{

      /*  list<ModuleInfo>::iterator itt;
        list<ModuleInfo>::iterator iStart = myCtl->modules.begin();
        list<ModuleInfo>::iterator iEnd = myCtl->modules.end();

        for (itt = iStart ; itt != iEnd ; ++itt)
           {
               if ( itt->getModuleName()==moduleName)
                   {
                   if (availableState == true)
                   {
                       itt->setFree();
                       Switch3D::switchToBar();
                       //delete SWC;
                      // bubble ("StateReleased");
                   }
                   else
                   {
                       itt->setBusy();
                       cout<<"I am busy"<<endl;

                   }

                   }// end of IF moduleType
               }*/
               }


        bool Switch3D::getModuleBusyStateTo(string moduleName)
        {
           /* bool currentState;

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
                return currentState;*/


        }




} /* namespace queueing */
