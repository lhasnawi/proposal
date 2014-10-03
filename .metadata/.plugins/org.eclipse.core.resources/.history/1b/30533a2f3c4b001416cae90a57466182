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

#include "SSSplitter.h"

namespace queueing {

Define_Module(SSSplitter);


P3DModuleCont * SSSplitter::genrateModuleCont(){
    P3DModuleCont * Mod = new P3DModuleCont();
    return Mod;
}
void SSSplitter::initialize()
{
    moduleUsed =false;
    barState = true;
}

void SSSplitter::handleMessage(cMessage *msg)
{
    if (msg->getKind()==3)
    {
        P3DBroadcastParameter * BP = check_and_cast<P3DBroadcastParameter *>(msg);
        this->numberOfTimeslots = BP->getNumberOfTimeslots();
        this->numberOfFrames = BP->getNumberOfFrames();
        this->numberOfJobs = this->numberOfTimeslots * this->numberOfFrames;
        delete msg;

        P3DModuleCont * splitterCont = SSSplitter::genrateModuleCont();
        splitterCont->setModuleID(this->getId());
        splitterCont->setModuleName(this->getName());
        splitterCont->setModuleType(2);
        splitterCont->setKind(2);
        send(splitterCont,"control$o");
    }
    else if (msg->getKind()==0)
    {
        if (moduleUsed == false)
           moduleUsed = true;

        switch (SSSplitter::getSwitchState())
        {
            case true:
            {
                send(msg,SSSplitter::gate("dataOut",0));
                break;
            }
            case false:
            {
                send(msg,SSSplitter::gate("dataOut",1));
                break;
            }

        }
    }

    else
    {
        delete msg;
    }
}

bool SSSplitter::getSwitchState()
{
    return barState;
}


} //namespace
