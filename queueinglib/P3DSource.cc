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

#include "P3DSource.h"

namespace queueing {

Define_Module(P3DSource);

P3DTimeslot * P3DSource::generateTimeslot(){
    TS = new P3DTimeslot();
    TS->setKind(0);
    TS->setByteLength(1500);
    TS->setName("Timeslot");
    TS->setTimeslotIndex(this->timeslotIndex);
    TS->setFrameIndex(this->frameIndex);
    TS->setWavelegnthIndex(par("wavelengthP"));
    increaseTimeslotIndex();
    return TS;

}

void P3DSource::initialize(){
    this->timeslotIndex=0;
    this->frameIndex=0;
    P3DSourceEvent = new cMessage();
    P3DSourceEvent->setKind(1);
    P3DSourceEvent->setName("SourceEvent");
    scheduleAt(1, P3DSourceEvent);
}

void P3DSource::handleMessage(cMessage *msg){
    if (msg->getKind()==3)
    {
        P3DBroadcastParameter * BP = check_and_cast<P3DBroadcastParameter *>(msg);
        this->numberOfTimeslots = BP->getNumberOfTimeslots();
        this->numberOfFrames = BP->getNumberOfFrames();
        this->numberOfJobs = this->numberOfTimeslots * this->numberOfFrames;
        delete msg;

        P3DModuleCont *osourceCont = P3DSource::genrateModuleCont();
        osourceCont->setModuleID(this->getId());
        osourceCont->setModuleName(this->getName());
        osourceCont->setModuleType(0);
        osourceCont->setKind(2);
        send(osourceCont,"control$o");




    }
    else if (msg->getKind()==1 && (this->frameIndex < this->numberOfFrames && this->timeslotIndex < this->numberOfTimeslots))
    {
        scheduleAt(simTime()+1, P3DSourceEvent);
        P3DTimeslot *TS = generateTimeslot();
        send (TS,"dataOut");

    }
    else
    {
        delete msg;
    }
}

void P3DSource::increaseTimeslotIndex() {

    this->timeslotIndex++;
    if (timeslotIndex >= numberOfTimeslots)
    {
        this->frameIndex++;
        this->timeslotIndex = 0;
    }
}

P3DModuleCont * P3DSource::genrateModuleCont(){
    P3DModuleCont * Mod = new P3DModuleCont();
    return Mod;
}

} //namespace
