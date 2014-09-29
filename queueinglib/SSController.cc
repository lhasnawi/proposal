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

#include "SSController.h"

namespace queueing {

Define_Module(SSController);

void SSController::initialize()
{
    this->numberOfTimeslots=par("numberOfTimeslotsP");
    this->numberOfFrames=par("numberOfFramesP");
    this->timeslotSize=1500; // 1500 byte
    this->dataRate = 12500000000; //100 Gps -> Byte/sec
    this->timeslotDuration = timeslotSize/dataRate;
    this->guardTime = this->timeslotDuration*.1;        //10% from timeslot duration
    SSController::broadcastParameter();
}

void SSController::handleMessage(cMessage *msg)
{
    if (msg->getKind()==2)
        send (msg,"modDB$o");
}

void SSController::broadcastParameter() {

    BC = new P3DBroadcastParameter();
    BC->setKind(3);
    BC->setName("Broadcast");
    BC->setNumberOfTimeslots(this->numberOfTimeslots);
    BC->setNumberOfFrames(this->numberOfFrames);
    BC->setTimeslotDuration(this->timeslotDuration);
    BC->setGuardTime(this->guardTime);


    for (int i=0; i<SSController::gateSize("control$o");i++)
        {
        P3DBroadcastParameter * BCP = BC->dup();
            send(BCP,"control$o",i);
        }
        delete BC;


}
} //namespace
