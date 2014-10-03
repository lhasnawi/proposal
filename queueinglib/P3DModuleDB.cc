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

bool P3DModuleDB::isBarState() const {
    return barState;
}

void P3DModuleDB::setBarState(bool barState) {
    this->barState = barState;
}

bool P3DModuleDB::isBusy() const {
    return busy;
}

int P3DModuleDB::getDelay() const {
    return delay;
}

void P3DModuleDB::setDelay(int delay) {
    this->delay = delay;
}


const cQueue& P3DModuleDB::getSwitchingContQ() const {
    return SwitchingContQ;
}

void P3DModuleDB::setSwitchingContQ(const cQueue& switchingContQ) {
    SwitchingContQ = switchingContQ;
}

void P3DModuleDB::setBusy(bool busy) {
    this->busy = busy;
}

void P3DModuleDB::insertOrderedSWC(SSSwitchingCont * sw)
{

    bool exit = false;
    int queueLegnth=0;

    queueLegnth = this->SwitchingContQ.getLength();

    if (SwitchingContQ.isEmpty()==true) //Case 1: Switching Control Queue is empty
    {
        //EV<<"Queue is Empty .. "<<endl;
        SwitchingContQ.insert(sw);
       // EV<<"DONE... Inserted to Empty Queue .. Length = "<<SwitchingContQ.getLength()<<endl;
        //EV<<"//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--"<<endl;
    } // end of IfEmpty
    else // Case 2: Switching Control Queue is NOT Empty
    {
       // EV<<"Queue is NOT Empty .. Length = "<<SwitchingContQ.getLength()<<endl;
        cQueue::Iterator currentIter =  cQueue::Iterator ( SwitchingContQ, 0);
        SSSwitchingCont * SWC = (  SSSwitchingCont *) currentIter();


        // case 2.1 Only one Job in Queue
        if (SwitchingContQ.length()==1)
        {
            // Case 2.1.1: Holding Time LESS than Head Of Queue
            if (sw->getStartHoldingTime() < SWC->getStartHoldingTime())
            {
                //EV<<"new SWC is LESS than the head of the Queue"<<endl;
                SwitchingContQ.insertBefore(currentIter.operator ()(),sw);
               // EV<<"DONE... Inserted to head of the queue where new SWC (Start Holding Time) ="<< sw->getStartHoldingTime() <<" and head of the Queue ReleaseTime =  "<<SWC->getStartHoldingTime()<<endl;
               // EV<<"DONE... Inserted to head of the queue where new SWC delay ="<< sw->getDelay() <<" and head of the Queue delay =  "<<SWC->getDelay()<<endl;
               // EV<<SwitchingContQ.getLength()<<endl;
               // EV<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
            }

            // Case 2.1.2 Holding Time GREATER than Head Of Queue and Only One Job in Queue
            else
            {
            //EV<<"new SWC is GREATER than the head of the Queue & only one job in Q"<<endl;
            SwitchingContQ.insertAfter(currentIter.operator ()(),sw);
           // EV<<"DONE... Inserted to tail of the queue where new SWC (Start Holding Time) ="<< sw->getStartHoldingTime() <<" and head of the Queue ReleaseTime =  "<<SWC->getStartHoldingTime()<<endl;
            //EV<<"DONE... Inserted to tail of the queue where new SWC delay ="<< sw->getDelay() <<" and head of the Queue delay =  "<<SWC->getDelay()<<endl;
            //EV<<SwitchingContQ.getLength()<<endl;
            //EV<<"--------------------------------------------------------------------------------"<<endl;
            } // end 2.1.2
        }
        // Case 2.2: More Than One Job in Queue
        else
        {
            //cQueue::Iterator currentIter =  cQueue::Iterator (* itt->SwitchingContQ, 0);
            cQueue::Iterator nextIter =  cQueue::Iterator ( SwitchingContQ, 0);
            nextIter++;
            SSSwitchingCont * SWCN;
            bool exit = false;


                SWC = (  SSSwitchingCont *) currentIter();
                SWCN = (  SSSwitchingCont *) nextIter();

                if (sw->getStartHoldingTime() < SWC->getStartHoldingTime())// && sw->getStartHoldingTime()< SWCN->getStartHoldingTime())
                {
                    SwitchingContQ.insertBefore(currentIter.operator ()(),sw);
                    exit = true;

                   // EV<<"DONE... Inserted to queue where new SWC (Start Holding Time) = "<< sw->getStartHoldingTime() <<" before   "<<SWC->getStartHoldingTime()<<endl;
                    //EV<<"DONE... Inserted to queue where new SWC delay = "<< sw->getDelay() <<" after  "<<SWC->getDelay()<<endl;
                    //EV<<itt->SwitchingContQ->getLength()<<endl;
                    //EV<<"cccccccccccccccccccccccccccccccccccccccccccccccccccccccccc"<<endl;
                }
                else //if (sw->getStartHoldingTime()>SWC->getStartHoldingTime())
                {
                    do
                    {
                        SWC = (  SSSwitchingCont *) currentIter();
                        SWCN = (  SSSwitchingCont *) nextIter();
                    if(nextIter.end()==true)
                    {
                    SwitchingContQ.insertAfter(currentIter.operator ()(),sw);
                    exit = true;
                    }
                    else if (sw->getStartHoldingTime()<SWCN->getStartHoldingTime())
                    {
                    SwitchingContQ.insertBefore(nextIter.operator ()(),sw);
                    exit = true;
                    }
                    else
                    {
                            currentIter++;
                            nextIter++;
                    }

                    }while (exit == false);
                }
        } // end case 2.2
    }// end case 2
}

int P3DModuleDB::getQueueLength() {
    return this->SwitchingContQ.getLength();
}

void P3DModuleDB::printSwitcchingContQ() {
    cQueue::Iterator currentIter =  cQueue::Iterator ( this->SwitchingContQ, 0);
    SSSwitchingCont * SWC;
    int counter=0;
    EV<<"=============================="<<endl;
    EV<<"Module ( "<<moduleName<<" )"<<endl;
    EV<<"Length = "<<this->SwitchingContQ.getLength()<<endl;
    EV<<"=============================="<<endl;

    for (currentIter; currentIter.end()==false;currentIter++)
    {
       SWC = (  SSSwitchingCont *) currentIter();

       EV<<"Job # "<<counter+1<<"-----------------"<<endl;
       EV<<"Start Holding Time  = "<<SWC->getStartHoldingTime()<<endl;
       EV<<"Switching State     = "<<SWC->getSwitchingState()<<endl;
       EV<<"Delay               = "<<SWC->getDelay()<<endl;
       EV<<"Release Time        = "<<SWC->getReleaseTime()<<endl;
       EV<<"Target Module       = "<<SWC->getTargetModule()<<endl;
       EV<<"Target Module ID    = "<<SWC->getTargetModuleID()<<endl;
       counter++;
    }

}

SSSwitchingCont * P3DModuleDB::getSWC() {
       cQueue::Iterator currentIter =  cQueue::Iterator ( SwitchingContQ, 0);
       SSSwitchingCont * contCurrent = (  SSSwitchingCont *) currentIter();
       if (SwitchingContQ.isEmpty()==0)
       {

           if (  contCurrent->getStartHoldingTime()== simTime())
               {
               SSSwitchingCont * SWC = new SSSwitchingCont (*contCurrent);
               return SWC;

               }
           else
           {
               return NULL;
           }
       }
}



void P3DModuleDB::popTheHead() {
    this->SwitchingContQ.pop();
}

} /* namespace queueing */


