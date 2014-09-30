/*
 * ModuleInfo.cc
 *
 *  Created on: Apr 14, 2013
 *      Author: Luai
 */

#include "ModuleInfo.h"

namespace queueing {



ModuleInfo::ModuleInfo()
{
    ModuleInfo::setBar();
    ModuleInfo::setFree();
    //SwitchingContQ = new cQueue;

}

ModuleInfo::~ModuleInfo()
{
    // TODO Auto-generated destructor stub
    nextModuleAtGate0=NULL;
    nextModuleAtGate1=NULL;
    //delete this->SwitchingContQ;
    //SwitchingContQ->~cQueue();
    //delete nextModuleAtGate0;
    //delete nextModuleAtGate1;
}

void ModuleInfo::setFrameType(int FT)
{
    this->frameType = FT;
}

void ModuleInfo::setModuleName(string MN)
{
    this->moduleName = MN;
}

void ModuleInfo::setModuleID(int MI)
{
    this->moduleID = MI;
}

void ModuleInfo::setModuleType(int MT)
{
    this->moduleType = MT;
}

void ModuleInfo::setControllerInputGateID(int CIGID)
{
        this->ControllerInputGateID = CIGID;
}

void ModuleInfo::setControllerOutputGateID(int COGID)
{
    this->ControllerOutputGateID = COGID;
}

void ModuleInfo::setNextModuleAtGate0( ModuleInfo * m)
{

        this->nextModuleAtGate0 =m;
}

void ModuleInfo::setNextModuleAtGate1( ModuleInfo * m)
{
        this->nextModuleAtGate1 =m;
}

// ModuleInfo getters

int ModuleInfo::getModuleCounter()
{
     return this->moduleCounter;
 }

int ModuleInfo::getFrameType()
{
     return this->frameType;
 }

string ModuleInfo::getModuleName()
{
     return this->moduleName;
 }

int ModuleInfo::getModuleID()
{
     return this->moduleID;
 }

int ModuleInfo::getModuleID(string moduleName)
{
    return this->moduleID;
}
int ModuleInfo::getModuleType()
{
     return this->moduleType;
 }

int ModuleInfo::getControllerInputGateID()
{
    return this->ControllerInputGateID;
}


int ModuleInfo::getControllerOutputGateID()
{
    return this->ControllerOutputGateID;
}

ModuleInfo*& ModuleInfo::getNextModuleAtGate0()
{
   return nextModuleAtGate0;
}

ModuleInfo* ModuleInfo::getNextModuletest()
{
   return nextModuleAtGate0;
}

bool ModuleInfo::isBusy()
{
    return available;
}

void ModuleInfo::setBusy()
{
    this->available = false;
}

void ModuleInfo::setFree()
{
    this->available = true;
}

const simtime_t& ModuleInfo::getReleaseHoldingTime() const
{
    return releaseHoldingTime;
}

void ModuleInfo::setReleaseHoldingTime(const simtime_t& releaseHoldingTime)
{
    this->releaseHoldingTime = releaseHoldingTime;
}

const simtime_t& ModuleInfo::getStartHoldingTime() const
{
    return startHoldingTime;
}

bool ModuleInfo::isBar()
{
    return this->barState;
}

void ModuleInfo::setBar()
{
    this->barState= true;
}

void ModuleInfo::setCross()
{
    this->barState=false;
}

int ModuleInfo::getDelay() const
{
    return delay;
}

void ModuleInfo::setDelay(int delay)
{
    this->delay = delay;
}

void ModuleInfo::setStartHoldingTime(const simtime_t& startHoldingTime)
{
    this->startHoldingTime = startHoldingTime;
}

ModuleInfo*& ModuleInfo::getNextModuleAtGate1()
{
    return nextModuleAtGate1;
}


int ModuleInfo::moduleCounter = 0;

void ModuleInfo::insertInOrder(SwitchingCont * sw)
{
    int newDelay = sw->getDelay();

    if (SwitchingContQ.isEmpty()==true) // Switching Control Queue is empty
    {
        SwitchingContQ.insert(sw);
    }
    /*else if (ModuleInfo::validateConflect(newDelay)==true) // there is SW for the same time delay
    {
        EV<<" @#$%@#$% Conflect Found @#$%@#$% "<<endl;
    }*/
    else
        {
        bool found = false;
        cQueue::Iterator currentIter =  cQueue::Iterator ( SwitchingContQ, 1);
        SwitchingCont * contCurrent = (  SwitchingCont *) currentIter();
        cQueue::Iterator nextIter =  cQueue::Iterator ( SwitchingContQ, 1);
        SwitchingCont * contNext = (  SwitchingCont *) nextIter();
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
            contCurrent = (  SwitchingCont *) currentIter();
            contNext = (  SwitchingCont *) nextIter();

            }
        }while (nextIter.end()!=true || found == false);
        }

}

bool ModuleInfo::validateConflect(int delay)
{
    cQueue::Iterator currentIter =  cQueue::Iterator ( SwitchingContQ, 1);
    SwitchingCont * contCurrent = (  SwitchingCont *) currentIter();
    bool conflectFound = false;
    for (currentIter ; currentIter.end()==false; currentIter++)
    {

        if (contCurrent->getDelay()==delay)
            conflectFound = conflectFound | true;
        else
            conflectFound = conflectFound | false;

    }
    return conflectFound;

}

bool ModuleInfo::queueIsEmpty()
{
    return SwitchingContQ.isEmpty();
}

} /* namespace queueing */
