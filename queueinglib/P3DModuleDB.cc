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

#include <P3DModuleDB.h>

namespace queueing {

P3DModuleDB::P3DModuleDB() {
    // TODO Auto-generated constructor stub

}

P3DModuleDB::~P3DModuleDB() {
    // TODO Auto-generated destructor stub
}



int P3DModuleDB::getContOutputPortId() const {
    return contOutputPortID;
}

void P3DModuleDB::setContOutputPortId(int contOutputPortId) {
    contOutputPortID = contOutputPortId;
}

int P3DModuleDB::getModuleId() const {
    return moduleID;
}

void P3DModuleDB::setModuleId(int moduleId) {
    moduleID = moduleId;
}

string P3DModuleDB::getModuleName() const {
    return moduleName;
}

void P3DModuleDB::setModuleName(string moduleName) {
    this->moduleName = moduleName;
}

int P3DModuleDB::getModuleType() const {
    return moduleType;
}

void P3DModuleDB::setModuleType(int moduleType) {
    this->moduleType = moduleType;
}

void P3DModuleDB::insertInOrder(SSSwitchingCont * sw)
{
    int newDelay = sw->getDelay();

    if (SwitchingContQ.isEmpty()==true) // Switching Control Queue is empty
    {
        SwitchingContQ.insert(sw);
    }
    else
        {
        bool found = false;
        cQueue::Iterator currentIter =  cQueue::Iterator ( SwitchingContQ, 1);
        SSSwitchingCont * contCurrent = (  SSSwitchingCont *) currentIter();
        cQueue::Iterator nextIter =  cQueue::Iterator ( SwitchingContQ, 1);
        SSSwitchingCont * contNext = (  SSSwitchingCont *) nextIter();
        nextIter++;
        do
        {

            if (newDelay < contCurrent->getDelay())
            {
                SwitchingContQ.insertBefore(currentIter.operator ()(),sw) ;
                found = true;
            }
            else if (newDelay > contCurrent->getDelay())
            {
                if (newDelay < contNext->getDelay())
                {
                    //SwitchingContQ->insertBefore(contNext.operator ()(),sw) ;
                    found = true;
                }

            }
            else
            {
            currentIter++;
            nextIter++;
            contCurrent = (  SSSwitchingCont *) currentIter();
            contNext = (  SSSwitchingCont *) nextIter();

            }
        }while (nextIter.end()!=true || found == false);
        }

}
} /* namespace queueing */
