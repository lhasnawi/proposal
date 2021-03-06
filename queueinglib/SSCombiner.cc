//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed dataIn the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "SSCombiner.h"

namespace queueing {

Define_Module(SSCombiner);

P3DModuleCont * SSCombiner::genrateModuleCont(){
    P3DModuleCont * Mod = new P3DModuleCont();
    return Mod;
}

void SSCombiner::initialize()
{
    moduleUsed =false;
    barState = true;
    droppedTS =0;
}

void SSCombiner::handleMessage(cMessage *msg)
{

     if (msg->getKind()==0)
    {
        if (moduleUsed == false)
        {
            moduleUsed = true;
        }

        if(this->barState==true)
        {
            // Set to Bar
            if(msg->arrivedOn("dataIn",0))
            {
                // Arrived at the right state
                send(msg,"dataOut");
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
            if(msg->arrivedOn("dataIn",1))
            {
                // Arrived at the right state
                send(msg,"dataOut");
            }
            else
            {
                   // Arrived at wrong State
                bubble ("Arrived at wrong State & blocked");
                this->droppedTS++;
            }

        }


    }
    else if (msg->getKind()==3)
    {
        P3DBroadcastParameter * BP = check_and_cast<P3DBroadcastParameter *>(msg);
        this->numberOfTimeslots = BP->getNumberOfTimeslots();
        this->numberOfFrames = BP->getNumberOfFrames();
        this->numberOfJobs = this->numberOfTimeslots * this->numberOfFrames;
        this->timeslotDuration = BP->getTimeslotDuration();
        this->guardTime = BP->getGuardTime();
        delete msg;

        P3DModuleCont * combinerCont = SSCombiner::genrateModuleCont();
        combinerCont->setModuleID(this->getId());
        combinerCont->setModuleName(this->getName());
        combinerCont->setModuleType(4);
        combinerCont->setKind(2);
        send(combinerCont,"control$o");
    }
    else if (msg->getKind()==4)       // it is control Packet
       {
           //Control Message
        SSSwitchingCont * cont = check_and_cast<SSSwitchingCont *>(msg);

           barState = cont->getSwitchingState();
           startHolding = cont->getStartHoldingTime();
           releaseTime =cont->getArrivalTime()+timeslotDuration*.9;
           releaseMessage = new cMessage();
           releaseMessage->setKind(5);
           releaseMessage->setName("releaseMessage");
           scheduleAt(releaseTime, releaseMessage);
           delete msg;
       }


    else if (msg->getKind()==5)
        {
            //Message to release switching state
        SSCombiner::setBarState(true);
            bubble ("StateReleased");
            cancelAndDelete (releaseMessage);



        }
}

bool SSCombiner::isBarState() const {
    return barState;
}

void SSCombiner::setBarState(bool barState) {
    this->barState = barState;
}

bool SSCombiner::getSwitchState()
{
    return barState;
}

} //namespace
