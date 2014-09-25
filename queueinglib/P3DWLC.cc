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

#include "P3DWLC.h"

namespace queueing {

Define_Module(P3DWLC);

void P3DWLC::initialize()
{
    // TODO - Generated method body
}

void P3DWLC::handleMessage(cMessage *msg)
{
    if (msg->getKind()==0)
    {
        P3DTimeslot * data = check_and_cast<P3DTimeslot *>(msg);
        data->setWavelegnthIndex(par("outWL"));
        send (msg,"dataOut");
    }
}

} //namespace
