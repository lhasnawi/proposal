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

#include "P3DController.h"

namespace queueing {

Define_Module(P3DController);



void P3DController::initialize()
{
    this->numberOfTimeslots=par("numberOfTimeslotsP");
    this->numberOfFrames=par("numberOfFramesP");
    P3DController::broadcastParameter();

}

void P3DController::handleMessage(cMessage *msg)
{
    if (msg->getKind()==1)
    {}
}

void P3DController::broadcastParameter() {

    BC = new P3DBroadcastParameter();
    BC->setKind(3);
    BC->setName("Broadcast");
    BC->setNumberOfTimeslots(this->numberOfTimeslots);
    BC->setNumberOfFrames(this->numberOfFrames);

    for (int i=0; i<P3DController::gateSize("control$o");i++)
        {
        P3DBroadcastParameter * BCP = BC->dup();
            send(BCP,"control$o",i);
        }
        delete BC;


}

} //namespace
