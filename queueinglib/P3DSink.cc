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

#include "P3DSink.h"


namespace queueing {

Define_Module(P3DSink);

void P3DSink::initialize()
{
    this->arrivals =0;
}

void P3DSink::handleMessage(cMessage *msg)
{
    if (msg->getKind()==3)
    {
        P3DBroadcastParameter * BP = check_and_cast<P3DBroadcastParameter *>(msg);
        this->numberOfTimeslots = BP->getNumberOfTimeslots();
        this->numberOfFrames = BP->getNumberOfFrames();
        delete msg;

        P3DModuleCont *sinkCont = P3DSink::genrateModuleCont();
        sinkCont->setModuleID(this->getId());
        sinkCont->setModuleName(this->getName());
        sinkCont->setModuleType(1);
        sinkCont->setKind(2);
        send(sinkCont,"control$o");

    }
    else if (msg->getKind()==0)
    {
        this->arrivals++;
        delete msg;
    }
}

P3DModuleCont * P3DSink::genrateModuleCont(){
    P3DModuleCont * Mod = new P3DModuleCont();
    return Mod;
}

} //namespace
