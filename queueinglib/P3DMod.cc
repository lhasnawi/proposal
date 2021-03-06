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

#include "P3DMod.h"

namespace queueing {

Define_Module(P3DMod);

void P3DMod::initialize()
{

}

void P3DMod::handleMessage(cMessage *msg)
{

        P3DModuleCont * modCont = check_and_cast<P3DModuleCont *>(msg);
        P3DModuleDB mod;
        switch(modCont->getModuleType())
        {
        case 0:
        {
            mod.setModuleId(modCont->getModuleID());
            mod.setModuleName(modCont->getModuleName());
            mod.setModuleType(modCont->getModuleType());
            mod.setContOutputPortId(modCont->getArrivalGateId());
            sourceSinkList.push_back(mod);
            delete msg;
            bubble ("Source added");
        }
            break;
        case 1:
        {
            mod.setModuleId(modCont->getModuleID());
            mod.setModuleName(modCont->getModuleName());
            mod.setModuleType(modCont->getModuleType());
            mod.setContOutputPortId(modCont->getArrivalGateId());
            sourceSinkList.push_back(mod);
            delete msg;
            bubble ("Sink added");
        }
            break;
        case 2:
        {
            mod.setModuleId(modCont->getModuleID());
            mod.setModuleName(modCont->getModuleName());
            mod.setModuleType(modCont->getModuleType());
            mod.setContOutputPortId(modCont->getArrivalGateId());
            switchesList.push_back(mod);
            delete msg;
            bubble ("Splitter added");
        }
            break;

        case 3:
        {
            mod.setModuleId(modCont->getModuleID());
            mod.setModuleName(modCont->getModuleName());
            mod.setModuleType(modCont->getModuleType());
            mod.setContOutputPortId(modCont->getArrivalGateId());
            switchesList.push_back(mod);
            delete msg;
            bubble ("Switch added");
        }
            break;
        case 4:
        {
            mod.setModuleId(modCont->getModuleID());
            mod.setModuleName(modCont->getModuleName());
            mod.setModuleType(modCont->getModuleType());
            mod.setContOutputPortId(modCont->getArrivalGateId());
            switchesList.push_back(mod);
            delete msg;
            bubble ("Combiner added");
        }
            break;
        }



}

} //namespace
