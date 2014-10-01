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

#include "Ocontroller.h"

namespace queueing {

void *myPtr = NULL;



Define_Module(Ocontroller);
extern void *srcPtr;

Ocontroller::Ocontroller()
{
    Ocontroller::setNumOfOcombiners(0);
    Ocontroller::setNumOfOfdls(0);
    Ocontroller::setNumOfOsplitters(0);
    Ocontroller::setNumOfOswtiches(0);

    this->timeslotCounter = 0;
    this->frameCounter = 0;
    this->pcounter = 0;
    this->tracktimeslot =0;
    //this->pathIdentifier =0;
    this->totalNumberOfPaths=0;
    myPtr = this;
    //cout<<"Set the pointer now"<<endl;

    //permutationFile.open("permutation8.txt");
    //SWCFile.open("SWC8.txt");


}

Ocontroller::~Ocontroller() {
    oFDLPointer = NULL;
    //permutationFile.close();
    //SWCFile.close();



    for (int i=0;i<Ocontroller::getNumTimeslots();i++)
        {
        delete [] pathNames[i];
        }
    delete[] pathNames;


    for (int i=0;i<Ocontroller::getNumberOfSwitchesInPath();i++)
        {
        delete []delayMatrix[i];
        delete []commulatedDelayMatrix[i];
        }
    delete[] delayMatrix;
    delete[] commulatedDelayMatrix;
    //delete []FDL;
    cancelAndDelete (event);
    cancelAndDelete (broadcastParameter);
    cancelAndDelete (OFDLMessage);
    cancelAndDelete (releaseOFDLBusyState);
    //delete []OFDLNames;
    //delete []OFDLBusyMatrix;
    //delete []delayStages;
    delete[] numberOfPaths;
    //delete []permutation;
   // delete []permutationList;

    list<ModuleInfo>::iterator it;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    modules.erase(iStart,iEnd);


   // modules.erase(iStart,iEnd);

    //delete cont;
    //delete SWCont;
    //delete parCont;



}

int Ocontroller::getNumberFromFile(int row, int column)
{
    int result = -1, rowIndex = 0;
    string temp;
    ifstream inFile;

    switch (Ocontroller::getNumTimeslots())
    {
        case 2:
        {
            if(row > 0 && column > 0)
            {
             inFile.open("permutation2.txt");

             for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
              inFile>>temp;

             inFile.close();

             if(rowIndex>=row && column<=temp.size())
              result = temp.at(column - 1) - '0';
            }
        }
            break;
        case 4:
        {
            if(row > 0 && column > 0)
            {
             inFile.open("permutation4.txt");

             for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
              inFile>>temp;

             inFile.close();

             if(rowIndex>=row && column<=temp.size())
              result = temp.at(column - 1) - '0';
            }

        }
            break;
        case 8:
        {
            if(row > 0 && column > 0)
            {
             inFile.open("permutation8.txt");

             for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
              inFile>>temp;

             inFile.close();

             if(rowIndex>=row && column<=temp.size())
              result = temp.at(column - 1) - '0';
            }
        }
            break;

    }




 return result;
}

int Ocontroller::getSWCFromFile(int row, int column)
{
 int result = -1, rowIndex = 0;
 string temp;
 ifstream inFile;

 switch (Ocontroller::getNumTimeslots())
 {
     case 2:
     {
         if(row > 0 && column > 0)
         {
          inFile.open("SWC2.txt");

          for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
           inFile>>temp;

          inFile.close();

          if(rowIndex>=row && column<=temp.size())
           result = temp.at(column - 1) - '0';
         }


     }
         break;
     case 4:
     {
         if(row > 0 && column > 0)
     {
      inFile.open("SWC4.txt");

      for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
       inFile>>temp;

      inFile.close();

      if(rowIndex>=row && column<=temp.size())
       result = temp.at(column - 1) - '0';
     }


     }
         break;
     case 8:
     {
         if(row > 0 && column > 0)
         {
          inFile.open("SWC8.txt");

          for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
           inFile>>temp;

          inFile.close();

          if(rowIndex>=row && column<=temp.size())
           result = temp.at(column - 1) - '0';
         }

     }
         break;

 }



 return result;
}

ContFrame * Ocontroller::genrateCont()
{
    ContFrame *cont = new ContFrame();
    return cont;

}

SwitchingCont * Ocontroller::genrateSWCont()
{
    SwitchingCont *SWCont = new SwitchingCont();
    return SWCont;

}

ParameterCont * Ocontroller::genrateParCont()
{
    ParameterCont *parCont = new ParameterCont();
    return parCont;

}

//Setters

void Ocontroller::setNumTimeslots(int numTS)
{
    this->numTimeslots=numTS;
}

void Ocontroller::setTimeslotsSize(int TSSize)
{
    this->timeslotSize = TSSize;
}

void Ocontroller::setNumFrames(int Frames)
{
    this->numFrames = Frames;
}

void Ocontroller::setDataRate(double DR)
{
    this->dataRate = DR;
}

void Ocontroller::setTimeslotDuration(int timeslotSize, double dataRate)
{
   this->timeslotDuration = timeslotSize/dataRate;
}

void Ocontroller::setInterArrivalTime()
{
    this->interArrivalTime = Ocontroller::getTimeslotDuration()+Ocontroller::getGuardTime();
}

void Ocontroller::setNumParametersOFDL (int P)
{
    this->numParametersOFDL = P;
}

void Ocontroller::setNumParametersOswitch (int P)
{
    this->numParametersOswitch = P;
}

void Ocontroller::setNumParametersOsplitter (int P)
{
    this->numParametersOsplitter = P;
}

void Ocontroller::setNumParametersOcombiner (int P)
{
    this->numParametersOcombiner = P;
}

void Ocontroller::setNumOfOsplitters(int numOfOsplitters)
{
    this->numOfOsplitters = numOfOsplitters;
}

void Ocontroller::setNumOfOcombiners(int numOfOcombiners)
{
    this->numOfOcombiners = numOfOcombiners;
}

void Ocontroller::setNumOfOswtiches(int numOfOswitces)
{
    this->numOfOswitches = numOfOswitces;
}

void Ocontroller::setNumOfOfdls(int numOfOfdls)
{
    this->numOfOfdls = numOfOfdls;
}

void Ocontroller::setFrameCounter(int frameCounter) {
    frameCounter = frameCounter;
}

void Ocontroller::setTimeslotCounter(int timeslotCounter) {
    this->timeslotCounter = timeslotCounter;
}


void Ocontroller::setNumberPermutations(int TS)
{
    unsigned int retval = 1;
    for (int i = TS; i > 1; --i)
        retval *= i;
    this->totalPermutations = retval;
}

void Ocontroller::setTimeSwitchingAssignment(int timeSwitchingAssignment)
{
    this->timeSwitchingAssignment = timeSwitchingAssignment;
}

void Ocontroller::setGuardTime(double timeslotDuration) {
    this->guardTime = timeslotDuration*.3;
}


void Ocontroller::setMaximumDelay(int TS) {
    this->maximumDelay = (2*TS)-1;
    Ocontroller::setNumberOfPaths();
}

//Getters

int Ocontroller::getNumTimeslots()
{
    return this->numTimeslots;
}

int Ocontroller::getTimeslotsSize()
{
    return this->timeslotSize;
}

int Ocontroller::getNumFrames()
{
    return this->numFrames;
}

int Ocontroller::getDataRate()
{
    return this->dataRate;
}

double Ocontroller::getTimeslotDuration()
{
    return this->timeslotDuration;
}

double Ocontroller::getInterArrivalTime()
{
    return this->interArrivalTime;
}

int Ocontroller::getNumParametersOFDL ()
{
    return this->numParametersOFDL;
}

int Ocontroller::getNumParametersOswitch ()
{
    return this->numParametersOswitch;
}

int Ocontroller::getNumParametersOsplitter ()
{
    return this->numParametersOsplitter;
}

int Ocontroller::getNumParametersOcombiner ()
{
    return this->numParametersOcombiner;
}

int Ocontroller::getModuleOutputID(int moduleID)
{

    list<ModuleInfo>::iterator it;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    int value;

    for (it = iStart ; it != iEnd ; ++it)
    {

        if ( it->getModuleID() == moduleID)
            value = it->ModuleInfo::getControllerOutputGateID();
    }
    return value;
}

int Ocontroller::getNumOfOsplitters()
{
    return numOfOsplitters;
}

int Ocontroller::getNumOfOcombiners()
{
    return numOfOcombiners;
}

int Ocontroller::getNumOfOswtiches()
{
    return numOfOswitches;
}

int Ocontroller::getNumOfOfdls()
{
    return numOfOfdls;
}

int Ocontroller::getFrameCounter() const {
    return frameCounter;
}

int Ocontroller::getTimeslotCounter() const {
    return timeslotCounter;
}

int Ocontroller::getNumberPermutations()
{
    return this->totalPermutations;
}

int Ocontroller::getTimeSwitchingAssignment() const
{
    return timeSwitchingAssignment;
}

int Ocontroller::getModuleIDByName(string moduleName)
{
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    int ModuleID;


    for (itt = iStart ; itt != iEnd ; ++itt)
       {

           if ( itt->getModuleName()==moduleName)
               {
               ModuleID = itt->ModuleInfo::getModuleID();
                   return ModuleID;
               }// end of IF moduleType
       }
}

ModuleInfo* Ocontroller::getModulePointer(int modID)
{
    ModuleInfo *mod;
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
          {
              if ( itt->moduleID==modID)
                  {
                    mod = &*itt;

                      return mod;
                  }// end of IF moduleType

          }


}

double Ocontroller::getGuardTime() const {
    return guardTime;
}


int Ocontroller::getMaximumDelay() const {
    return maximumDelay;
}


// End of Getters and Setters

void Ocontroller::increaseFrameCounter()
{
   if (this->frameCounter<Ocontroller::getNumFrames()-1)
   {
    this->frameCounter++;

   }
   else
   {
       Ocontroller::setFrameCounter(0);

   }
}

void Ocontroller::increaseTimeslotCounter()
{
    if (Ocontroller::getTimeslotCounter()<Ocontroller::getNumTimeslots()-1)
        this->timeslotCounter++;
    else
    {
        Ocontroller::setTimeslotCounter(0);
        Ocontroller::increaseFrameCounter();
    }

}

void Ocontroller::initialize()
{



    WATCH(numJobs);
    WATCH(currentFrameScheduled);
    WATCH(nextFrameScheduled);
    WATCH(currentTimeslotScheduled);
    WATCH(nextTimeslotScheduled);
    WATCH(timeSwitchingAssignment);
    WATCH(timeSwitchingAssignmentOdd);
    WATCH(timeSwitchingAssignmentEven);
    WATCH(timeslotSize);
    WATCH(dataRate);
    WATCH(interArrivalTime);
    WATCH(timeslotDuration);
    WATCH(guardTime);
    WATCH(jobCounter);
    Ocontroller::setNumTimeslots(par("numTimeslotsP"));
    Ocontroller::setNumFrames(par("numFramesP"));
    Ocontroller::setTimeslotsSize(par("timeslotSizeP"));
    Ocontroller::setDataRate(par("dataRateP"));
    Ocontroller::setTimeslotDuration(this->timeslotSize, this->dataRate);
    Ocontroller::setGuardTime(this->timeslotDuration);
    Ocontroller::setInterArrivalTime();
    Ocontroller::setCaseIndex(par("caseIndex"));
    switch (Ocontroller::getCaseIndex())
    {
    case 0:
    {
        Ocontroller::setTimeSwitchingAssignment(par("switchingAssignment"));
    }
        break;
    case 1:
    {
        Ocontroller::setTimeSwitchingAssignment(par("switchingAssignment"));
    }
        break;
    case 2:
    {
        Ocontroller::setTimeSwitchingAssignmentOdd(par("switchingAssignmentOdd"));
        Ocontroller::setTimeSwitchingAssignmentEven(par("switchingAssignmentEven"));

    }
        break;
    }


    this->numJobs=Ocontroller::getNumFrames()*Ocontroller::getNumTimeslots();
    this->jobCounter=0;


    ModuleInfo mod;
    this->nextTimeslotScheduled =0;
    this->currentTimeslotScheduled=-1;
    this->nextFrameScheduled=0;
    this->currentFrameScheduled=-1;
    this->interArrivalTime = 0;

    mod.frameType = 0;
    mod.moduleName = Ocontroller::getName();
    mod.moduleID = Ocontroller::getId();
    mod.moduleType = 2;
    mod.setFree();

    modules.push_back(mod);

    this->SCCounter =0;

    // Set Broadcast Parameters Message
    broadcastParameter = new cMessage();
    broadcastParameter->setName("broadcastParameter");
    broadcastParameter->setKind(1);
    scheduleAt(0, broadcastParameter);

    // Build OFDL Matrix
    OFDLMessage = new cMessage();
    OFDLMessage->setName("OFDLMessage");
    OFDLMessage->setKind(2);
    scheduleAt(.5, OFDLMessage);

    //Schedule the First Message for sync
    event = new cMessage();
    event->setName("event");
    event->setKind(3);
    scheduleAt(1, event);

    releaseOFDLBusyState = new cMessage();
    releaseOFDLBusyState->setName("releaseOFDLBusyState");
    releaseOFDLBusyState->setKind(4);


}

void Ocontroller::handleMessage(cMessage *msg)
{
//========= Cont. Frame ===================
if (strcmp(msg->getClassName(),"queueing::ContFrame")==0)
{

    ContFrame * cont = check_and_cast<ContFrame *>(msg);

            ModuleInfo mod;
            mod.frameType = cont->getFrameType();
            //EV<<"Frame Type is "<< mod.getFrameType()<<endl;
            mod.moduleName = cont->getModuleName();
            //EV<<"ModuleName is "<<mod.getModuleName()<<endl;
            mod.moduleID = cont->getModuleID();
            //EV<<"ModuleID is "<<mod.getModuleID()<<endl;
            mod.moduleType = cont->getModuleType();
            //EV<<"ModuleType is "<<mod.getModuleType()<<endl;
            mod.ControllerInputGateID = cont->getArrivalGateId();// msg->getArrivalGateId();
            //EV<<"Controller input gate ID is "<<mod.getControllerInputGateID()<<endl;
            mod.setFree();
            mod.setBar();
            //mod.SwitchingContQ = new cQueue;
            //EV<<"Module Busy State..."<<mod.isBusy()<<endl;



            for (int i=0;i<Ocontroller::gateSize("control$o");i++)
                {
                    cGate * outputGate = Ocontroller::gate("control$o",i);
                    if (outputGate->getNextGate()== simulation.getModule(mod.moduleID)->gate("control$i"))
                        mod.ControllerOutputGateID = outputGate->getId();
                }
            //EV<<"Controller output gate ID is "<<mod.getControllerOutputGateID()<<endl;
            //Ocontroller::setNextModulePointer(&mod);

            modules.push_back(mod);
             cont->removeFromOwnershipTree();






}//end StringComp ContFrame

//========= Broadcast Message. ===================

else if (strcmp(msg->getName(),"broadcastParameter")==0)
       {
                Ocontroller::broadcastParameters();
                Ocontroller::setNumberPermutations(Ocontroller::getNumTimeslots());
               // Ocontroller::genPermutation(Ocontroller::getNumTimeslots());
                Ocontroller::setMaximumDelay(Ocontroller::getNumTimeslots());
                Ocontroller::computeOswitchStages(Ocontroller::getNumTimeslots());
                Ocontroller::computeOsplitterStages(Ocontroller::getNumTimeslots());
                Ocontroller::computeOcombinerStages(Ocontroller::getNumTimeslots());
                Ocontroller::setNumberOfSwitchesInPath();
                //Ocontroller::setSwitchingControl();
                Ocontroller::setPathNames();
                Ocontroller::setDelayMatrix();
                Ocontroller::buildFDL();
                //Ocontroller::setOFDLBusyMatrix();
                //Ocontroller::setDelayStages();
                Ocontroller::computeNumberOFDLs(Ocontroller::getNumOfOfdlStages());

                if (srcPtr != NULL)
                {
                    mySRC = (Osource*)srcPtr;

                }
                else
                {
                    mySRC = NULL;
                    cout<<"ERROR Controller Pointer @ Combiner"<<endl;
                }
       }

//========= Event Message used for Sync System. ===================
else if (msg->getKind()==3)
{
    switch (Ocontroller::getCaseIndex())
    {
    case 0:
    {
        EV<<"Number of Jobs at source = "<<mySRC->getNumJobs()<<" Job Counter at source = "<<mySRC->getJobCounter()<<endl;

        if ( mySRC->getNumJobs() > mySRC->getJobCounter())
        {

        int inTS;
        int outTS;
        int pathIndex;
        int PathNamesIndex;
        int delay;
        int SWAssingment;

       inTS = Ocontroller::getTimeslotCounter();
       SWAssingment = Ocontroller::getTimeSwitchingAssignment();
       //outTS = Ocontroller::permutationList[SWAssingment][inTS];
       outTS = Ocontroller::getNumberFromFile(SWAssingment+1, inTS+1);
       EV<<"Current Timeslot @ Controller is . . . "<< inTS<<endl;
       EV<<"Current Frame @ Controller is . . . "<< Ocontroller::getFrameCounter()<<endl;
       EV<<"output switching for TS "<< inTS<< "is . . ."<<outTS<<endl;
       delay = Ocontroller::computeDelay(inTS,outTS);
       EV<<"required delay for switching TS "<< inTS<< " to "<<outTS<< " is . . . "<<delay<<endl;
       pathIndex= Ocontroller::selectPath(delay);
       PathNamesIndex = Ocontroller::getPathNamesIndex(pathIndex);
       EV<<"Path Names Index is  "<< PathNamesIndex<<endl;
       Ocontroller::reservePath(PathNamesIndex, pathIndex, delay);
       //Ocontroller::reserveOFDLStage(PathNamesIndex,delay);
       //Ocontroller::sendSwitchingCont(PathNamesIndex, pathIndex, delay);
       Ocontroller::sendSwitchingCont();

       scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
       Ocontroller::increaseTimeslotCounter();
       this->jobCounter++;

        }
        else
        {   EV<<"I am here ....1 "<<endl;
            if (Ocontroller::allSWCQEmpty()==false)
           {
                EV<<"I am here ....2 "<<endl;
               Ocontroller::sendSwitchingCont();
               scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
               Ocontroller::increaseTimeslotCounter();

           }
            else
                {
                EV<<"I am here ....3 "<<endl;
                Ocontroller::finish();
                }


        }


    }// End of Case 0
        break;
    case 1:
    {
        EV<<"Number of Jobs at source = "<<mySRC->getNumJobs()<<" Job Counter at source = "<<mySRC->getJobCounter()<<endl;

        if ( mySRC->getNumJobs() > mySRC->getJobCounter())
        {

        int inTS;
        int outTS;
        int pathIndex;
        int PathNamesIndex;
        int delay;
        int SWAssingment;


       inTS = Ocontroller::getTimeslotCounter();
       SWAssingment = Ocontroller::getTimeSwitchingAssignment();
       outTS = Ocontroller::getNumberFromFile(SWAssingment+1, inTS+1);//Ocontroller::permutationList[SWAssingment][inTS];
       EV<<"Current Timeslot @ Controller is . . . "<< inTS<<endl;
       EV<<"Current Frame @ Controller is . . . "<< Ocontroller::getFrameCounter()<<endl;
       EV<<"output switching for TS "<< inTS<< "is . . ."<<outTS<<endl;
       delay = Ocontroller::computeDelay(inTS,outTS);
       EV<<"required delay for switching TS "<< inTS<< " to "<<outTS<< " is . . . "<<delay<<endl;
       pathIndex= Ocontroller::selectPath(delay);
       PathNamesIndex = Ocontroller::getPathNamesIndex(pathIndex);
       EV<<"Path Names Index is  "<< PathNamesIndex<<endl;
       Ocontroller::reservePath(PathNamesIndex, pathIndex, delay);
       //Ocontroller::reserveOFDLStage(PathNamesIndex,delay);
       //Ocontroller::sendSwitchingCont(PathNamesIndex, pathIndex, delay);
       Ocontroller::sendSwitchingCont();

       scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
       Ocontroller::increaseTimeslotCounter();
       this->jobCounter++;

        }
        else
            {
            if (Ocontroller::allSWCQEmpty()==false)
            {
                Ocontroller::sendSwitchingCont();
                scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
                Ocontroller::increaseTimeslotCounter();
            }
            else
            {
                Ocontroller::finish();
            }
            }

    }
        break;
    case 2:
    {
        EV<<"Number of Jobs at source = "<<mySRC->getNumJobs()<<" Job Counter at source = "<<mySRC->getJobCounter()<<endl;

        if ( mySRC->getNumJobs() > mySRC->getJobCounter())
        {

        int inTS;
        int outTS;
        int pathIndex;
        int PathNamesIndex;
        int delay;
        int SWAssingment;

        inTS = Ocontroller::getTimeslotCounter();
       if(Ocontroller::getFrameCounter()%2==0)
       {
           SWAssingment = Ocontroller::getTimeSwitchingAssignmentEven();
       }
       else
       {
           SWAssingment = Ocontroller::getTimeSwitchingAssignmentOdd();

       }

       outTS = Ocontroller::getNumberFromFile(SWAssingment+1, inTS+1);//Ocontroller::permutationList[SWAssingment][inTS];
       EV<<"Current Timeslot @ Controller is . . . "<< inTS<<endl;
       EV<<"Current Frame @ Controller is . . . "<< Ocontroller::getFrameCounter()<<endl;
       EV<<"output switching for TS "<< inTS<< "is . . ."<<outTS<<endl;
       delay = Ocontroller::computeDelay(inTS,outTS);
       EV<<"required delay for switching TS "<< inTS<< " to "<<outTS<< " is . . . "<<delay<<endl;
       pathIndex= Ocontroller::selectPath(delay);
       PathNamesIndex = Ocontroller::getPathNamesIndex(pathIndex);
       EV<<"Path Names Index is  "<< PathNamesIndex<<endl;
       Ocontroller::reservePath(PathNamesIndex, pathIndex, delay);
       //Ocontroller::reserveOFDLStage(PathNamesIndex,delay);
       //Ocontroller::sendSwitchingCont(PathNamesIndex, pathIndex, delay);
       Ocontroller::sendSwitchingCont();

       scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
       Ocontroller::increaseTimeslotCounter();
       this->jobCounter++;

        }
            else
            {
                EV<<"I am here ....1 "<<endl;
                if (Ocontroller::allSWCQEmpty()==false)
                    {
                    EV<<"I am here ....2 "<<endl;
                    Ocontroller::sendSwitchingCont();
                    scheduleAt(simTime()+Ocontroller::getTimeslotDuration(), event);
                    Ocontroller::increaseTimeslotCounter();

                    }
                else
                    {
                    EV<<"I am here ....3 "<<endl;
                    Ocontroller::finish();
                    }


            }

    }// end of case 2
        break;
    }

}

//=========  OFDL  ===================
else if (msg->getKind()==2)
{
    Ocontroller::setAllNextModulesPointer();
    //Ocontroller::setOFDLNames();
}



}// handleMessage



/*void Ocontroller::sendSwitchingCont(int pathNamesIndex, int SWCIndex, int delay)
{
    EV<<"Just started Sending SW Cont"<<endl;
    int modID;
    int outputIndex;


    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    SwitchingCont *  SWC;// = Ocontroller::genrateSWCont();


    for (int i=0; i<Ocontroller::getNumberOfSwitchesInPath() ; ++i)
     {
        simtime_t currentTime = simTime();

        SWC = Ocontroller::genrateSWCont();
    for (itt = iStart ; itt != iEnd ; ++itt)
       {

           if ( itt->getModuleName()==Ocontroller::getPathNames(pathNamesIndex,i))
               {
                   cQueue::Iterator currentIter =  cQueue::Iterator (* itt->SwitchingContQ, 0);
                   SwitchingCont *  contCurrent = (  SwitchingCont *) currentIter();
                   modID = itt->getModuleID();
                   outputIndex = Ocontroller::getModuleOutputID(modID);
                   SWC->setSwitchingState(contCurrent->getSwitchingState());
                   SWC->setDelay(contCurrent->getDelay());
                   SWC->setStartHoldingTime(contCurrent->getStartHoldingTime());
                   SWC->setReleaseTime(contCurrent->getReleaseTime());
                   SWC->setTargetModule(itt->getModuleName().c_str());
                   SWC->setKind(contCurrent->getKind());
                   SWC->setName(contCurrent->getName());
                   //EV<< "&&&& Current Time is... "<<currentTime<<" .. Release Time for Module ... "<<itt->getModuleName()<<".... "<<SWC->getReleaseTime()<<"&&&&"<<endl;

                   //if ( ((simTime()+Ocontroller::getGuardTime())<SWC->getReleaseTime() )&& (simTime()+Ocontroller::getTimeslotDuration()+Ocontroller::getGuardTime()> SWC->getReleaseTime()))
                       if (simTime()==SWC->getStartHoldingTime())
                   {
                   EV<< "&&&& simTime()+Ocontroller::getGuardTime() =  "<<simTime()+Ocontroller::getGuardTime()<<" .. SWC->getReleaseTime()=  "<<SWC->getReleaseTime()<<endl;
                   EV<< "&&&& currentTime =  "<<currentTime<<endl;

                   itt->SwitchingContQ->pop();
                   EV<<itt->getModuleName()<<"  Queue new length After Poping the SWC from is ... "<<itt->SwitchingContQ->length()<<endl;
                   send(SWC,outputIndex);
                   }
               }// end of IF moduleType
       }




     }

}*/

void Ocontroller::sendSwitchingCont()
{
    EV<<"Just started Sending SW Cont (** No Parameters **)"<<endl;
    int modID;
    int outputIndex;


    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();



    for (itt = iStart ; itt != iEnd ; ++itt)
       {
        if (itt->getModuleType()==4 || itt->getModuleType()== 5 || itt->getModuleType()==6)
            {

                   cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                   SwitchingCont * contCurrent = (  SwitchingCont *) currentIter();
                   if (itt->SwitchingContQ.isEmpty()==0)

                   {
                       //   if (  contCurrent->getStartHoldingTime()*.95<= simTime() &&  contCurrent->getStartHoldingTime()*1.05 >= simTime() )


                   if (  contCurrent->getStartHoldingTime()== simTime())
                       {

                           SwitchingCont *  SWC = contCurrent;// = Ocontroller::genrateSWCont();
                           modID = itt->getModuleID();
                           outputIndex = Ocontroller::getModuleOutputID(modID);
                           SWC->setSwitchingState(contCurrent->getSwitchingState());
                           SWC->setDelay(contCurrent->getDelay());
                           SWC->setStartHoldingTime(contCurrent->getStartHoldingTime());
                           SWC->setReleaseTime(contCurrent->getReleaseTime());
                           SWC->setTargetModule(itt->getModuleName().c_str());
                           SWC->setKind(contCurrent->getKind());
                           SWC->setName(contCurrent->getName());

                           itt->SwitchingContQ.pop();
                           //EV<<itt->getModuleName()<<"  Queue new length After Poping the SWC from is ... "<<itt->SwitchingContQ->length()<<endl;
                           send(SWC,outputIndex);




                   }
                   }



            }


       }// end of IF moduleType




}

bool Ocontroller::allSWCQEmpty()
{

    bool SWCQEmpty=true;


    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

   // SwitchingCont *  SWC;// = Ocontroller::genrateSWCont();

    for (itt = iStart ; itt != iEnd ; ++itt)
       {
        if (itt->getModuleType()==4 || itt->getModuleType()== 5 || itt->getModuleType()==6)
            {
                   cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                   SwitchingCont *  contCurrent = (  SwitchingCont *) currentIter();
                   SWCQEmpty= SWCQEmpty& itt->SwitchingContQ.isEmpty();
            }


        }
    return SWCQEmpty;



}


void Ocontroller::buildFDL()
{

       // totalChannels =numFrames*numTimeslots;          //Compute total Number of Channels

        //timeslotDuration = dataRate/timeslotSize;       // Compute timeslot duration



       int K= log(Ocontroller::getMaximumDelay())/log(2);

        if(pow(2,K+1)>Ocontroller::getMaximumDelay())                     // value of K must satisfy 0 <= K <= K-1
            K++;

        Ocontroller::setNumOfOfdlStages(K);
        //EV<<" STAGES = "<<Ocontroller::getNumOfOfdlStages()<<"     OFDL-OFDL-OFDL-OFDL-OFDL"<<endl;
       /* FDL = new double [K];                           // Build FDL
        for (int i=0; i<K ; i++)
            FDL[i] = pow(2,i) * Ocontroller::getTimeslotDuration();*/

}

int Ocontroller::computeDelay(int in, int out)
{
    int delay=0;
    delay = Ocontroller::getNumTimeslots()+out-in;
    return delay;
}

void Ocontroller::computeOswitchStages(int TS)
{
    int numOswitches=0;
    int maxDelay = Ocontroller::getMaximumDelay();

    //int K=(int)log(maxDelay)/log(2);
    int result = 0;
    //if(result<maxDelay)                     // value of K must satisfy 0 <= K <= K-1
       // K++;
    int k=0;
    do
    {
        result = pow(2,k);
        k++;

    }while (result<maxDelay);

    //EV<<"Test k  in compute statages. . ."<< k<<endl;
    //EV<<"Test result  in compute statages. . ."<< result<<endl;
    numOswitches = k-2;
    //EV<<"Test Number of Oswitch in compute statages. . ."<< numOswitches<<endl;
    Ocontroller::setNumOfOswitchStages(numOswitches);

}

void Ocontroller::computeOsplitterStages(int TS)
{


        int counter=1;
        double result;


        if (TS%2 == 0)
            {
                result = TS/2;
                counter++;
            }
        else
            {
                result = ceil((double)TS/2);
                counter++;
            }


        for (int i=0;result>1;i++)

        {
            if ((int)result%2 == 0)
                {
                    result = result/2;
                    counter++;
                }
            else
                {
                    result = ceil((double)result/2);
                    counter++;
                }

        }
        Ocontroller::setNumOfOsplitterStages(counter);
}

void Ocontroller::computeOcombinerStages(int TS)
{
        int counter=1;
        double result;


        if (TS%2 == 0)
            {
                result = TS/2;
                counter++;
            }
        else
            {
                result = ceil((double)TS/2);
                counter++;
            }

        for (int i=0;result>1;i++)

        {
            if ((int)result%2 == 0)
                {
                    result = result/2;
                    counter++;
                }
            else
                {
                    result = ceil((double)result/2);
                    counter++;
                }

        }
        Ocontroller::setNumOfOcombinerStages(counter);
}

void Ocontroller::increaseNumOfOsplitters()
{
    this->numOfOsplitters++;
}

void Ocontroller::increaseNumOfOcombiners()
{
    this->numOfOcombiners++;
}

void Ocontroller::increaseNumOfOswitches()
{
    this->numOfOswitches++;
}

void Ocontroller::increaseNumOfOfdls()
{
    this->numOfOfdls++;
}

void Ocontroller::setOFDLDelay()
{
    list<ModuleInfo>::iterator it;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

   double delay = Ocontroller::getTimeslotDuration();
    int ID;

    for (it = iStart ; it != iEnd ; ++it)
    {
        if ( it->getModuleType() == 3)
            {
                ID = it->ModuleInfo::getModuleID();
                oFDLPointer = simulation.getModule(ID);

                    for (int i=0; i<Ocontroller::getNumParametersOFDL(); i++)
                            {
                                cPar& p = oFDLPointer->par(i);
                                    if (strcmp(p.getName(),"serviceTime")==0)
                                    {
                                        p.setDoubleValue(delay);

                                    }
                           }
            }// end of IF moduleType

    }


}

/*void Ocontroller::setSwitchingControl()
{
    // Building the switching Matrix.
    const int totalNumOfPaths = Ocontroller::getTotalNumberOfPaths();
    const int numSWPerPath = Ocontroller::getNumberOfSwitchesInPath();

    switchingControl  = new bool *[numSWPerPath];
    for (int i=0;i<numSWPerPath;i++)
        {
        switchingControl[i]=new bool[totalNumOfPaths];
        }


    EV<<"Number of Oswitches Stages are . . "<< Ocontroller::getNumOfOswitchStages()<<endl;
    EV<<"Number of Osplitter Stages are . . "<< Ocontroller::getNumOfOsplitterStages()<<endl;
    EV<<"Number of Ocombiner Stages are . . "<< Ocontroller::getNumOfOcombinerStages()<<endl;
    EV<<"Number of Switches in Path are . . "<< Ocontroller::getNumberOfSwitchesInPath()<<endl;

    // since it is a binary tree, then , half of each delay path is located in the upper and half on the lower next splitter of the matrix.

    // Set First column of the matrix such that first (n mod TS rows) for delay i where i=1,2.... Maximum Delay
    // Example: TS = 4, MaxD =7, TotalPaths = 28
    //Matrix (row (0-3) D=1) Row(4-7) D=2 . . . etc.
    //this will sort each delay path in sequence
    int devider = Ocontroller::getNumTimeslots()/2;
    int lastDevider;
    for (int x = 0; x < numSWPerPath;x++) // column traversal (only splitters
{

    if (x<Ocontroller::getNumOfOsplitterStages()) // splitters
    {
        if (x>=0 && x<Ocontroller::getNumOfOsplitterStages()-1) // splitters All splitter stages except the one befor OFDL
        {


            for (int y=0;y<totalNumOfPaths-devider; y=y+(2*devider)) // add values to columns
            {
                for(int i=y;i<y+devider;i++)
                {
                    switchingControl[x][i] = true;
                   // EV<<"value x = "<<x<<" value y = "<<y<<" value i = "<<i<<" Bool value = "<<switchingControl[x][i]<< endl;
                    switchingControl[x][i+devider] = false;
                   // EV<<"value x = "<<x<<" value y = "<<y<<" value i = "<<i<<" Bool value = "<<switchingControl[x][i+devider]<<" value devider = " << devider<<endl;
                }
            }//end for
            if (devider>1)
            {
                devider=devider/2;
            }

        }

            else // splitter stages before OFDL only
            {
                cout<<"splitter stages before OFDL only"<<endl;
                bool state = true;
                for (int y=0;y<totalNumOfPaths; y+=Ocontroller::getNumTimeslots()) // add values to columns
                {
                    for ( int i=0 ; i<Ocontroller::getNumTimeslots();i++)
                    {
                        switchingControl[x][y+i] = state;
                    }
                    state = ! state;
                }
            }
        lastDevider = devider;


    } // End of Splitters
    //------------------------------------------------------------------------------

    else if (x>=Ocontroller::getNumOfOsplitterStages() && x<(Ocontroller::getNumOfOsplitterStages()+Ocontroller::getNumOfOswitchStages())) // switches
    {
        if (x==Ocontroller::getNumOfOsplitterStages())// first stage of Oswitch
        {

            bool state=false;
            int y=0;
            do {
                for (int i=0; i<Ocontroller::getNumTimeslots()*2; i++)
                {
                    switchingControl[x][y+i]=state;

                }
                y=y+(Ocontroller::getNumTimeslots()*2);
                state = !state;
            } while (y<totalNumOfPaths-Ocontroller::getNumTimeslots()-1);
            for (int y=totalNumOfPaths-Ocontroller::getNumTimeslots(); y<totalNumOfPaths; y++)
            {
                switchingControl[x][y]=state;
            }

        }
        else if (x==Ocontroller::getNumOfOsplitterStages()+1)
        {

            int counter=0;
            bool state=true;

            // first path, set all  to TRUE
                for (int i=0; i<Ocontroller::getNumTimeslots(); i++)
                {
                    switchingControl[x][i]=state;
                }
            state = !state;


                for (int i=Ocontroller::getNumTimeslots(); i<totalNumOfPaths; i+=Ocontroller::getNumTimeslots())
                {

                    if (counter >3)
                    {
                     counter = 0;
                     state = !state;
                    }

                    for (int y=0;y<Ocontroller::getNumTimeslots();y++)
                    {
                        switchingControl[x][y+i]=state;

                    }
                    counter++;

                }

        }
        else if (x==Ocontroller::getNumOfOsplitterStages()+2)
        {
            int counter=0;
            bool state=true;

            // first 3 paths, set all to TRUE
            for (int i=0; i<Ocontroller::getNumTimeslots()*3; i++)
            {
                switchingControl[x][i]=state;
            }
            state = !state;


            for (int i=Ocontroller::getNumTimeslots()*3; i<totalNumOfPaths; i+=Ocontroller::getNumTimeslots())
            {

                if (counter >7)
                {
                    counter = 0;
                    state = !state;
                }

                for (int y=0;y<Ocontroller::getNumTimeslots();y++)
                {
                    switchingControl[x][y+i]=state;

                }
                counter++;

            }
        }

        else // other switches stages
        {
            int counter=0;
            bool state=true;

            // first 7 paths, set all to TRUE
            for (int i=0; i<Ocontroller::getNumTimeslots()*7; i++)
            {
                switchingControl[x][i]=state;
            }
            state = !state;


            for (int i=Ocontroller::getNumTimeslots()*7; i<totalNumOfPaths; i+=Ocontroller::getNumTimeslots())
            {
                counter++;
                if (counter >16)
                {
                    counter = 0;
                    state = !state;
                }

                for (int y=0;y<Ocontroller::getNumTimeslots();y++)
                {
                    switchingControl[x][y+i]=state;

                }
            }
        }

    }// end of Switches
    //------------------------------------------------------------------------------
    else  // combiners
    {


        if (x==(numSWPerPath-Ocontroller::getNumOfOcombinerStages())) // first combiner after OFDL
        {
                for (int y=0 ; y<(Ocontroller::getNumTimeslots()*(Ocontroller::getNumTimeslots()-1));y++)
                {
                    switchingControl[x][y] = false;
                }
                for (int y=Ocontroller::getNumTimeslots()*(Ocontroller::getNumTimeslots()-1);y<totalNumOfPaths;y++)
                {
                    switchingControl[x][y] = true;
                }
            devider = lastDevider;
        }// end of first stage after OFDL

        else // rest of the combiners
        {

            for (int y=0;y<totalNumOfPaths-devider; y=y+(2*devider)) // add values to columns
            {
                for(int i=y;i<y+devider;i++)
                {
                    switchingControl[x][i] = true;
                    switchingControl[x][i+devider] = false;
                }

            }//end for
            devider = devider*2;

        }

}// end of Combiners
//------------------------------------------------------------------------------

}// end of For Columns


/*
 *
 * uncoment this section to seee outputs
 *
 *
 for (int y=0;y<totalNumOfPaths;y++)
{
    if (y<100)
    EV<<"Path "<<y<<'\t'<<'\t';

    else
        EV<<"Path "<<y<<'\t';
    for (int x=0;x<numSWPerPath;x++)
    {
        EV<<switchingControl[x][y]<<'\t';

        //SWCFile<<switchingControl[x][y];

    }
    EV<<endl;
    //SWCFile<<endl;

}


}*/

int Ocontroller::getNumOfOcombinerStages() const {
    return numOfOcombinerStages;
}

void Ocontroller::setNumOfOcombinerStages(int numOfOcombinerStages) {
    this->numOfOcombinerStages = numOfOcombinerStages;
}

int Ocontroller::getNumOfOsplitterStages() const {
    return numOfOsplitterStages;
}

void Ocontroller::setNumOfOsplitterStages(int numOfOsplitterStages) {
    this->numOfOsplitterStages = numOfOsplitterStages;
}

int Ocontroller::getNumOfOswitchStages() const {
    return numOfOswitchStages;
}

void Ocontroller::setNumOfOswitchStages(int numOfOswitchStages) {
    this->numOfOswitchStages = numOfOswitchStages;
}

int Ocontroller::getNumberOfSwitchesInPath() const {
    return numberOfSwitchesInPath;
}

void Ocontroller::setNumberOfSwitchesInPath() {
    this->numberOfSwitchesInPath = Ocontroller::getNumOfOswitchStages()+Ocontroller::getNumOfOsplitterStages()+Ocontroller::getNumOfOcombinerStages();
}

string Ocontroller::getPathNames(int x, int y)  {
    return pathNames[x][y];
}


void Ocontroller::setPathNames()
{
    const int numTS =Ocontroller::getNumTimeslots();
    const int numSWinPath =Ocontroller::getNumberOfSwitchesInPath();
    pathNames  = new string *[numTS];
    for (int i=0;i<numTS;i++)
        {
        pathNames[i]=new string [numSWinPath];
        }

   switch (Ocontroller::getNumTimeslots())
   {
                   case 2:
                   {
                       pathNames [0][0]="osplitter0";
                       pathNames [0][1]="osplitter11";
                       pathNames [0][2]="oswitch";
                       pathNames [0][3]="ocombiner11";
                       pathNames [0][4]="ocombiner0";

                       //===================
                       pathNames [1][0]="osplitter0";
                       pathNames [1][1]="osplitter12";
                       pathNames [1][2]="oswitch1";
                       pathNames [1][3]="ocombiner21";
                       pathNames [1][4]="ocombiner0";


                   }
                   break;
                   case 4:
                   {
                       pathNames [0][0]="osplitter0";
                       pathNames [0][1]="osplitter1";
                       pathNames [0][2]="osplitter11";
                       pathNames [0][3]="oswitch10";
                       pathNames [0][4]="oswitch11";
                       pathNames [0][5]="ocombiner11";
                       pathNames [0][6]="ocombiner1";
                       pathNames [0][7]="ocombiner0";
                       //===================
                       pathNames [1][0]="osplitter0";
                       pathNames [1][1]="osplitter1";
                       pathNames [1][2]="osplitter12";
                       pathNames [1][3]="oswitch20";
                       pathNames [1][4]="oswitch21";
                       pathNames [1][5]="ocombiner12";
                       pathNames [1][6]="ocombiner1";
                       pathNames [1][7]="ocombiner0";
                       //===================
                       pathNames [2][0]="osplitter0";
                       pathNames [2][1]="osplitter2";
                       pathNames [2][2]="osplitter21";
                       pathNames [2][3]="oswitch30";
                       pathNames [2][4]="oswitch31";
                       pathNames [2][5]="ocombiner21";
                       pathNames [2][6]="ocombiner2";
                       pathNames [2][7]="ocombiner0";
                       //===================
                       pathNames [3][0]="osplitter0";
                       pathNames [3][1]="osplitter2";
                       pathNames [3][2]="osplitter22";
                       pathNames [3][3]="oswitch40";
                       pathNames [3][4]="oswitch41";
                       pathNames [3][5]="ocombiner22";
                       pathNames [3][6]="ocombiner2";
                       pathNames [3][7]="ocombiner0";

                   }
                   break;

                   case 8:
                   {
                       pathNames [0][0]="osplitter0";
                       pathNames [0][1]="osplitter1";
                       pathNames [0][2]="osplitter11";
                       pathNames [0][3]="osplitter111";
                       pathNames [0][4]="oswitch0";
                       pathNames [0][5]="oswitch1";
                       pathNames [0][6]="oswitch2";
                       pathNames [0][7]="ocombiner111";
                       pathNames [0][8]="ocombiner11";
                       pathNames [0][9]="ocombiner1";
                       pathNames [0][10]="ocombiner0";
                       //===================
                       pathNames [1][0]="osplitter0";
                       pathNames [1][1]="osplitter1";
                       pathNames [1][2]="osplitter11";
                       pathNames [1][3]="osplitter112";
                       pathNames [1][4]="oswitch3";
                       pathNames [1][5]="oswitch4";
                       pathNames [1][6]="oswitch5";
                       pathNames [1][7]="ocombiner112";
                       pathNames [1][8]="ocombiner11";
                       pathNames [1][9]="ocombiner1";
                       pathNames [1][10]="ocombiner0";
                       //===================
                       pathNames [2][0]="osplitter0";
                       pathNames [2][1]="osplitter1";
                       pathNames [2][2]="osplitter12";
                       pathNames [2][3]="osplitter121";
                       pathNames [2][4]="oswitch6";
                       pathNames [2][5]="oswitch7";
                       pathNames [2][6]="oswitch8";
                       pathNames [2][7]="ocombiner121";
                       pathNames [2][8]="ocombiner12";
                       pathNames [2][9]="ocombiner1";
                       pathNames [2][10]="ocombiner0";
                       //===================
                       pathNames [3][0]="osplitter0";
                       pathNames [3][1]="osplitter1";
                       pathNames [3][2]="osplitter12";
                       pathNames [3][3]="osplitter122";
                       pathNames [3][4]="oswitch9";
                       pathNames [3][5]="oswitch10";
                       pathNames [3][6]="oswitch11";
                       pathNames [3][7]="ocombiner122";
                       pathNames [3][8]="ocombiner12";
                       pathNames [3][9]="ocombiner1";
                       pathNames [3][10]="ocombiner0";
                       //===================
                       pathNames [4][0]="osplitter0";
                       pathNames [4][1]="osplitter2";
                       pathNames [4][2]="osplitter21";
                       pathNames [4][3]="osplitter211";
                       pathNames [4][4]="oswitch12";
                       pathNames [4][5]="oswitch13";
                       pathNames [4][6]="oswitch14";
                       pathNames [4][7]="ocombiner211";
                       pathNames [4][8]="ocombiner21";
                       pathNames [4][9]="ocombiner2";
                       pathNames [4][10]="ocombiner0";
                       //===================
                       pathNames [5][0]="osplitter0";
                       pathNames [5][1]="osplitter2";
                       pathNames [5][2]="osplitter21";
                       pathNames [5][3]="osplitter212";
                       pathNames [5][4]="oswitch15";
                       pathNames [5][5]="oswitch16";
                       pathNames [5][6]="oswitch17";
                       pathNames [5][7]="ocombiner212";
                       pathNames [5][8]="ocombiner21";
                       pathNames [5][9]="ocombiner2";
                       pathNames [5][10]="ocombiner0";
                       //===================
                       pathNames [6][0]="osplitter0";
                       pathNames [6][1]="osplitter2";
                       pathNames [6][2]="osplitter22";
                       pathNames [6][3]="osplitter221";
                       pathNames [6][4]="oswitch18";
                       pathNames [6][5]="oswitch19";
                       pathNames [6][6]="oswitch20";
                       pathNames [6][7]="ocombiner221";
                       pathNames [6][8]="ocombiner22";
                       pathNames [6][9]="ocombiner2";
                       pathNames [6][10]="ocombiner0";
                       //===================
                       pathNames [7][0]="osplitter0";
                       pathNames [7][1]="osplitter2";
                       pathNames [7][2]="osplitter22";
                       pathNames [7][3]="osplitter222";
                       pathNames [7][4]="oswitch21";
                       pathNames [7][5]="oswitch22";
                       pathNames [7][6]="oswitch23";
                       pathNames [7][7]="ocombiner222";
                       pathNames [7][8]="ocombiner22";
                       pathNames [7][9]="ocombiner2";
                       pathNames [7][10]="ocombiner0";

                   }
                   break;
                   case 16:
                   {
                       pathNames [0][0]="";
                       pathNames [0][1]="";
                       pathNames [0][2]="";
                       pathNames [0][3]="";
                       pathNames [0][4]="";
                       pathNames [0][5]="";
                       pathNames [0][6]="";
                       pathNames [0][7]="";
                       pathNames [0][8]="";
                       pathNames [0][9]="";
                       pathNames [0][10]="";
                       pathNames [0][11]="";
                       pathNames [0][12]="";
                       pathNames [0][13]="";
                       //===================
                       pathNames [1][0]="";
                       pathNames [1][1]="";
                       pathNames [1][2]="";
                       pathNames [1][3]="";
                       pathNames [1][4]="";
                       pathNames [1][5]="";
                       pathNames [1][6]="";
                       pathNames [1][7]="";
                       pathNames [1][8]="";
                       pathNames [1][9]="";
                       pathNames [1][10]="";
                       pathNames [1][11]="";
                       pathNames [1][12]="";
                       pathNames [1][13]="";
                       //===================
                       pathNames [2][0]="";
                       pathNames [2][1]="";
                       pathNames [2][2]="";
                       pathNames [2][3]="";
                       pathNames [2][4]="";
                       pathNames [2][5]="";
                       pathNames [2][6]="";
                       pathNames [2][7]="";
                       pathNames [2][8]="";
                       pathNames [2][9]="";
                       pathNames [2][10]="";
                       pathNames [2][11]="";
                       pathNames [2][12]="";
                       pathNames [2][13]="";
                       //===================
                       pathNames [3][0]="";
                       pathNames [3][1]="";
                       pathNames [3][2]="";
                       pathNames [3][3]="";
                       pathNames [3][4]="";
                       pathNames [3][5]="";
                       pathNames [3][6]="";
                       pathNames [3][7]="";
                       pathNames [3][8]="";
                       pathNames [3][9]="";
                       pathNames [3][10]="";
                       pathNames [3][11]="";
                       pathNames [3][12]="";
                       pathNames [3][13]="";
                       //===================
                       pathNames [4][0]="";
                       pathNames [4][1]="";
                       pathNames [4][2]="";
                       pathNames [4][3]="";
                       pathNames [4][4]="";
                       pathNames [4][5]="";
                       pathNames [4][6]="";
                       pathNames [4][7]="";
                       pathNames [4][8]="";
                       pathNames [4][9]="";
                       pathNames [4][10]="";
                       pathNames [4][11]="";
                       pathNames [4][12]="";
                       pathNames [4][13]="";
                       //===================
                       pathNames [5][0]="";
                       pathNames [5][1]="";
                       pathNames [5][2]="";
                       pathNames [5][3]="";
                       pathNames [5][4]="";
                       pathNames [5][5]="";
                       pathNames [5][6]="";
                       pathNames [5][7]="";
                       pathNames [5][8]="";
                       pathNames [5][9]="";
                       pathNames [5][10]="";
                       pathNames [5][11]="";
                       pathNames [5][12]="";
                       pathNames [5][13]="";
                       //===================
                       pathNames [6][0]="";
                       pathNames [6][1]="";
                       pathNames [6][2]="";
                       pathNames [6][3]="";
                       pathNames [6][4]="";
                       pathNames [6][5]="";
                       pathNames [6][6]="";
                       pathNames [6][7]="";
                       pathNames [6][8]="";
                       pathNames [6][9]="";
                       pathNames [6][10]="";
                       pathNames [6][11]="";
                       pathNames [6][12]="";
                       pathNames [6][13]="";
                       //===================
                       pathNames [7][0]="";
                       pathNames [7][1]="";
                       pathNames [7][2]="";
                       pathNames [7][3]="";
                       pathNames [7][4]="";
                       pathNames [7][5]="";
                       pathNames [7][6]="";
                       pathNames [7][7]="";
                       pathNames [7][8]="";
                       pathNames [7][9]="";
                       pathNames [7][10]="";
                       pathNames [7][11]="";
                       pathNames [7][12]="";
                       pathNames [7][13]="";
                       //===================
                       pathNames [8][0]="";
                       pathNames [8][1]="";
                       pathNames [8][2]="";
                       pathNames [8][3]="";
                       pathNames [8][4]="";
                       pathNames [8][5]="";
                       pathNames [8][6]="";
                       pathNames [8][7]="";
                       pathNames [8][8]="";
                       pathNames [8][9]="";
                       pathNames [8][10]="";
                       pathNames [8][11]="";
                       pathNames [8][12]="";
                       pathNames [8][13]="";
                       //===================
                       pathNames [9][0]="";
                       pathNames [9][1]="";
                       pathNames [9][2]="";
                       pathNames [9][3]="";
                       pathNames [9][4]="";
                       pathNames [9][5]="";
                       pathNames [9][6]="";
                       pathNames [9][7]="";
                       pathNames [9][8]="";
                       pathNames [9][9]="";
                       pathNames [9][10]="";
                       pathNames [9][11]="";
                       pathNames [9][12]="";
                       pathNames [9][13]="";
                       //===================
                       pathNames [10][0]="";
                       pathNames [10][1]="";
                       pathNames [10][2]="";
                       pathNames [10][3]="";
                       pathNames [10][4]="";
                       pathNames [10][5]="";
                       pathNames [10][6]="";
                       pathNames [10][7]="";
                       pathNames [10][8]="";
                       pathNames [10][9]="";
                       pathNames [10][10]="";
                       pathNames [10][11]="";
                       pathNames [10][12]="";
                       pathNames [10][13]="";
                       //===================
                       pathNames [11][0]="";
                       pathNames [11][1]="";
                       pathNames [11][2]="";
                       pathNames [11][3]="";
                       pathNames [11][4]="";
                       pathNames [11][5]="";
                       pathNames [11][6]="";
                       pathNames [11][7]="";
                       pathNames [11][8]="";
                       pathNames [11][9]="";
                       pathNames [11][10]="";
                       pathNames [11][11]="";
                       pathNames [11][12]="";
                       pathNames [11][13]="";
                       //===================
                       pathNames [12][0]="";
                       pathNames [12][1]="";
                       pathNames [12][2]="";
                       pathNames [12][3]="";
                       pathNames [12][4]="";
                       pathNames [12][5]="";
                       pathNames [12][6]="";
                       pathNames [12][7]="";
                       pathNames [12][8]="";
                       pathNames [12][9]="";
                       pathNames [12][10]="";
                       pathNames [12][11]="";
                       pathNames [12][12]="";
                       pathNames [12][13]="";
                       //===================
                       pathNames [13][0]="";
                       pathNames [13][1]="";
                       pathNames [13][2]="";
                       pathNames [13][3]="";
                       pathNames [13][4]="";
                       pathNames [13][5]="";
                       pathNames [13][6]="";
                       pathNames [13][7]="";
                       pathNames [13][8]="";
                       pathNames [13][9]="";
                       pathNames [13][10]="";
                       pathNames [13][11]="";
                       pathNames [13][12]="";
                       pathNames [13][13]="";
                       //===================
                       pathNames [14][0]="";
                       pathNames [14][1]="";
                       pathNames [14][2]="";
                       pathNames [14][3]="";
                       pathNames [14][4]="";
                       pathNames [14][5]="";
                       pathNames [14][6]="";
                       pathNames [14][7]="";
                       pathNames [14][8]="";
                       pathNames [14][9]="";
                       pathNames [14][10]="";
                       pathNames [14][11]="";
                       pathNames [14][12]="";
                       pathNames [14][13]="";
                       //===================
                       pathNames [15][0]="";
                       pathNames [15][1]="";
                       pathNames [15][2]="";
                       pathNames [15][3]="";
                       pathNames [15][4]="";
                       pathNames [15][5]="";
                       pathNames [15][6]="";
                       pathNames [15][7]="";
                       pathNames [15][8]="";
                       pathNames [15][9]="";
                       pathNames [15][10]="";
                       pathNames [15][11]="";
                       pathNames [15][12]="";
                       pathNames [15][13]="";
                   }
                   break;

                   default:
                       EV<<"Invalid Number of Timeslots";
   }
   for (int i=0; i<numTS;i++)
   {
       EV<<"Path "<< i<<'\t';
       for (int j=0;j<numSWinPath;j++)
           EV<<pathNames[i][j]<<'\t';
       EV<<endl;
   }
}

/*bool Ocontroller::getSwitchingControl(int x, int y)
{
    return switchingControl[x][y];
}*/

int Ocontroller::selectPath(int delay)
{
    bool pathAvailable=true;
    bool pathQueueIsEmpty=true;
    bool pathQueueConflect = false;
    bool pathSwitchingConflect = false;

    int p=0;
    int startDelayIndex = 0;
    int endDelayIndex = 0;
    bool exit = false;


    simtime_t startHoldingTime;

    startDelayIndex = Ocontroller::getNumTimeslots()*(delay-1);
    endDelayIndex = startDelayIndex+Ocontroller::getNumTimeslots()-1;

    EV<<"Switching Control Paths starts at "<< startDelayIndex<<" and Ends at "<<endDelayIndex<<endl;



    do  // this do-while try to search for path in the SWControl matrics from the start index to the end index
    {
        pathAvailable = true;
        pathQueueIsEmpty=true;
        pathQueueConflect = false;
        pathSwitchingConflect = false;


        EV<<" Checking Delay Index ...."<<startDelayIndex<<endl;

        // check the delay matric if modules are available
        // and if the queue is empty
        // case 1
        for (int j= 0; j< Ocontroller::getNumberOfSwitchesInPath(); j++)
        {

            pathAvailable=pathAvailable & Ocontroller::getModuleBusyStateByName(Ocontroller::getPathNames(p,j));
            pathQueueIsEmpty= pathQueueIsEmpty & Ocontroller::queueIsEmpty(Ocontroller::getPathNames(p,j));
            //if (j>=(Ocontroller::getNumberOfSwitchesInPath()-Ocontroller::getNumOfOcombinerStages()) && simeTime()==1)
            //startHoldingTime= (simTime()+this->commulatedDelayMatrix[j][delay]*Ocontroller::getTimeslotDuration()+Ocontroller::getTimeslotDuration()/*+this->commulatedDelayMatrix[i][delay]*Ocontroller::getGuardTime()*/);
            //else
            startHoldingTime = simTime()+this->commulatedDelayMatrix[j][delay]*Ocontroller::getTimeslotDuration();
            EV<<" %SP Module "<<Ocontroller::getPathNames(p,j)<<" SwitchingControl ["<<Ocontroller::getSWCFromFile(startDelayIndex+1,j+1)<<"] Start Holding Time = "<<startHoldingTime<<endl;
        }


        // case 1.1 All modules are available and all Queues are Empty
        if (pathQueueIsEmpty==true && pathAvailable == true)
        {
            // Start Reserve the Path
            EV<<"**********************************************************************"<<endl;
            EV<<" Available Path index is..." <<p<<endl;
            EV<<" Available SW Control index is..." <<startDelayIndex<<endl;
            EV<<"**********************************************************************"<<endl;
            exit = true;
        }
        else //(pathQueueIsEmpty != true)
        {
            // validate conflict
            for (int j= 0; j< Ocontroller::getNumberOfSwitchesInPath(); j++)
            {
                startHoldingTime = simTime()+this->commulatedDelayMatrix[j][delay]*Ocontroller::getTimeslotDuration();
                pathQueueConflect = pathQueueConflect | Ocontroller::validateConflect(startHoldingTime,Ocontroller::getPathNames(p,j),Ocontroller::getSWCFromFile(startDelayIndex+1,j+1));
                EV<<" Module "<<Ocontroller::getPathNames(p,j)<<" Path Conflict ["<<pathQueueConflect<<"] ";
                //pathSwitchingConflect =pathSwitchingConflect | Ocontroller::validateSwitchingConflect(Ocontroller::getSWCFromFile(startDelayIndex+1,j+1),Ocontroller::getPathNames(p,j));
                //EV<<" Swiching Conflict ["<<pathSwitchingConflect<<"] "<<endl;

            }


            if (pathQueueConflect == true )
            {
                EV<<"$$$$$$$$$ Conflict exist, Go to Next path $$$$$$$$$$$$$$$$$ "<<p <<"   "<<startDelayIndex<<endl;
                p++;
                startDelayIndex++;
            }
            else
            {
                // Start Reserve the Path
                EV<<"**********************************************************************"<<endl;
                EV<<" Available Path index is..." <<p<<endl;
                EV<<" Available SW Control index is..." <<startDelayIndex<<endl;
                EV<<"**********************************************************************"<<endl;
                exit = true;

            }

        }

    } while (exit == false);

    return startDelayIndex;

} // end of select path

void Ocontroller::reservePath(int pathNamesIndex,int pathIndex, int delay)
{
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    int modID;
    string moduleName;
    SwitchingCont * SWCont;
    int commulatedDelay=0;


    for (int i = 0; i< Ocontroller::getNumberOfSwitchesInPath(); i++)
    {
        SWCont= Ocontroller::genrateSWCont();
        moduleName = this->pathNames[pathNamesIndex][i];

        for (itt = iStart ; itt != iEnd ; ++itt)
        {
            if ( itt->getModuleName()==moduleName)
                {


                //EV<<"Module Found ( "<<pathNames[pathNamesIndex][i]<<" )";
                itt->setBusy();
                //EV<<"  Module Available?  "<<itt->isBusy()<<endl;

                itt->setDelay(commulatedDelayMatrix[i][delay]);
                /*
                 * Start Holding Time is not going to be used since it is in the Queue in the SWC
                 * itt->setStartHoldingTime(simTime()+commulatedDelayMatrix[i][delay]*Ocontroller::getTimeslotDuration());
                 * EV<<"Start Holding Time "<<itt->getStartHoldingTime()<<endl;
                 */

                /*
                 * Release Holding  is not going to be used since it is in the Queue in the SWC
                 * itt->setReleaseHoldingTime(simTime()+commulatedDelayMatrix[i][delay]*Ocontroller::getTimeslotDuration()+Ocontroller::getGuardTime());
                 * */

                //EV<<"Delay Set = "<<itt->getDelay()<<" Release Schedualed till "<<itt->getReleaseHoldingTime()<<endl;
                ////////////////////////////////
                bool SWCfromFile = Ocontroller::getSWCFromFile(pathIndex+1,i+1);
                EV<<" Switching Control valeue "<<SWCfromFile<<endl;
                SWCont->setSwitchingState(SWCfromFile/*switchingControl[i][pathIndex]*/);
                modID = itt->getModuleID();
                SWCont->setKind(4);
                SWCont->setName("SWC");
                SWCont->setOutputPortIndex(Ocontroller::getModuleOutputID(modID));
                SWCont->setDelay(commulatedDelay);

                //if (itt->getModuleType()==6 && Ocontroller::getTimeslotCounter()!=0)
                //SWCont->setStartHoldingTime(simTime()+this->commulatedDelayMatrix[i][delay]*Ocontroller::getTimeslotDuration()+Ocontroller::getTimeslotDuration()/*+this->commulatedDelayMatrix[i][delay]*Ocontroller::getGuardTime()*/);
                //else
                SWCont->setStartHoldingTime(simTime()+this->commulatedDelayMatrix[i][delay]*Ocontroller::getTimeslotDuration()/*+this->commulatedDelayMatrix[i][delay]*Ocontroller::getGuardTime()*/);

                SWCont->setReleaseTime(simTime()+commulatedDelayMatrix[i][delay]*Ocontroller::getTimeslotDuration()+Ocontroller::getGuardTime());
                SWCont->setTargetModule(itt->getModuleName().c_str());

                //Validate No duplicate
                if (Ocontroller::validateDuplicate(SWCont,moduleName)==true)
                {
                    EV<<"Start inserting to Queue"<<endl;

                   Ocontroller::insertSWCInOrder(SWCont,moduleName);

                }
                else
                    delete SWCont;

                }// end of Module !=6



        }

    }
    EV<<"Path Names  ..."<< pathNamesIndex<<" is resrerved"<<endl;
}



bool Ocontroller::getModuleSwitchingStateByName(string moduleName)
{
       list<ModuleInfo>::iterator itt;
       list<ModuleInfo>::iterator iStart = modules.begin();
       list<ModuleInfo>::iterator iEnd = modules.end();

       bool ModuleSwitchingState;


       for (itt = iStart ; itt != iEnd ; ++itt)
          {
              if ( itt->getModuleName()==moduleName)
                  {
                  ModuleSwitchingState = itt->isBar();

                  }// end of IF moduleType
          }
       return ModuleSwitchingState;
}

bool Ocontroller::getModuleBusyStateByName(string moduleName)
{
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    bool ModuleBusyState;


    for (itt = iStart ; itt != iEnd ; ++itt)
       {
           if ( itt->getModuleName()==moduleName)
               {
               ModuleBusyState = itt->isBusy();

               }// end of IF moduleType
       }
    return ModuleBusyState;
}

int Ocontroller::getPathNamesIndex(int SWCIndex)
{
    return SWCIndex%Ocontroller::getNumTimeslots();
}

void Ocontroller::setDelayMatrix()
{

    // Building Delay Matrix.
       const int MaximumDelayPlus1 = Ocontroller::getMaximumDelay()+1;
       const int numSWPerPath = Ocontroller::getNumberOfSwitchesInPath();
       this->delayMatrix  = new int *[numSWPerPath];
       this->commulatedDelayMatrix = new int *[numSWPerPath];
       int multiplier = 1;

       for (int i=0;i<numSWPerPath;i++)
           {
           delayMatrix[i]=new int[MaximumDelayPlus1];
           commulatedDelayMatrix[i]=new int[MaximumDelayPlus1];
           }

       // Setting up the Splitters columns ( No delay )

       for (int sp=0; sp<Ocontroller::getNumOfOsplitterStages();sp++)
       {

           for (int s=0; s<MaximumDelayPlus1;s++)
           {
               delayMatrix[sp][s]=0;
           }

       }

       // Setting up the Switches and First Combiner columns

       for (int sw=Ocontroller::getNumOfOsplitterStages(); sw<Ocontroller::getNumberOfSwitchesInPath()-Ocontroller::getNumOfOswitchStages();sw++)
       {
           for (int y=0;y<MaximumDelayPlus1-multiplier; y=y+(2*multiplier))
                  {
                      for(int i=y;i<y+multiplier;i++)
                      {
                          delayMatrix[sw][i] = 0;
                          delayMatrix[sw][i+multiplier] = multiplier;
                      }

                  }//end for
           multiplier = multiplier*2;

              }



       // Setting up the Combiners columns ( No delay exept first Column )

       for (int co=Ocontroller::getNumberOfSwitchesInPath()-Ocontroller::getNumOfOcombinerStages()+1; co<Ocontroller::getNumberOfSwitchesInPath();co++)
       {

           for (int s=0; s<MaximumDelayPlus1;s++)
           {
               delayMatrix[co][s]=0;
           }

       }

       /*
        * uncomment this section for outputs
        *
        *for (int i=0;i<MaximumDelayPlus1;i++)
           {
           EV<<"delay "<<i<<"  ";
           for (int x = 0; x <Ocontroller::getNumberOfSwitchesInPath(); x++)
           {
               EV<<delayMatrix[x][i]<<"   ";
           }
           EV<<endl;

           }
        */
       int currentDelay=0;
       int previousDelay = 0;

       for (int i=0;i<MaximumDelayPlus1;i++)
           {
                   currentDelay=0;
                   previousDelay = 0;
                 //  EV<<"Cumulated  Delay "<<i<<"  ";
                   for (int x = 0; x <Ocontroller::getNumberOfSwitchesInPath(); x++)
                   {
                       currentDelay=previousDelay+ delayMatrix[x][i];
                       this->commulatedDelayMatrix[x][i]=currentDelay;
                    //   EV<<commulatedDelayMatrix[x][i]<<"   ";
                       previousDelay = currentDelay;

                   }
          // EV<<endl;
           }
}

bool Ocontroller::queueIsEmpty(string moduleName)
{
        list<ModuleInfo>::iterator itt;
       list<ModuleInfo>::iterator iStart = modules.begin();
       list<ModuleInfo>::iterator iEnd = modules.end();

       bool isEmpty;


       for (itt = iStart ; itt != iEnd ; ++itt)
          {
              if ( itt->getModuleName()==moduleName)
                  {
                  isEmpty = itt->queueIsEmpty();

                  }// end of IF moduleType
          }
       return isEmpty;
}

void Ocontroller::insertSWCInOrder(SwitchingCont * sw, string moduleName)
{
    // assuming no conflict in startHoldingTime
    //EV<<"Start Inserting for Module Name "  <<moduleName<<endl;
    bool exit = false;
    int queueLegnth=0;


    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    for (itt = iStart ; itt != iEnd ; itt++)
       {
            if ( itt->getModuleName()==moduleName)
            {
                queueLegnth = itt->SwitchingContQ.getLength();

                if (itt->SwitchingContQ.isEmpty()==true) //Case 1: Switching Control Queue is empty
                {
                    //EV<<"Queue is Empty .. "<<endl;
                    itt->SwitchingContQ.insert(sw);
                    //EV<<"DONE... Inserted to Empty Queue .. Length = "<<itt->SwitchingContQ->getLength()<<endl;
                    //EV<<"//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--//--"<<endl;
                } // end of IfEmpty

                else // Case 2: Switching Control Queue is NOT Empty
                {
                    //EV<<"Queue is NOT Empty .. Length = "<<itt->SwitchingContQ->getLength()<<endl;
                    cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                    SwitchingCont * SWC = (  SwitchingCont *) currentIter();


                    // case 2.1 Only one Job in Queue
                    if (itt->SwitchingContQ.length()==1)
                    {
                        // Case 2.1.1: Holding Time LESS than Head Of Queue
                        if (sw->getStartHoldingTime() < SWC->getStartHoldingTime())
                        {
                            //EV<<"new SWC is LESS than the head of the Queue"<<endl;
                            itt->SwitchingContQ.insertBefore(currentIter.operator ()(),sw);
                            //EV<<"DONE... Inserted to head of the queue where new SWC (Start Holding Time) ="<< sw->getStartHoldingTime() <<" and head of the Queue ReleaseTime =  "<<SWC->getStartHoldingTime()<<endl;
                            //EV<<"DONE... Inserted to head of the queue where new SWC delay ="<< sw->getDelay() <<" and head of the Queue delay =  "<<SWC->getDelay()<<endl;
                            //EV<<itt->SwitchingContQ->getLength()<<endl;
                            //EV<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
                        }

                        // Case 2.1.2 Holding Time GREATER than Head Of Queue and Only One Job in Queue
                        else
                        {
                        //EV<<"new SWC is GREATER than the head of the Queue & only one job in Q"<<endl;
                        itt->SwitchingContQ.insertAfter(currentIter.operator ()(),sw);
                        //EV<<"DONE... Inserted to tail of the queue where new SWC (Start Holding Time) ="<< sw->getStartHoldingTime() <<" and head of the Queue ReleaseTime =  "<<SWC->getStartHoldingTime()<<endl;
                        //EV<<"DONE... Inserted to tail of the queue where new SWC delay ="<< sw->getDelay() <<" and head of the Queue delay =  "<<SWC->getDelay()<<endl;
                        //EV<<itt->SwitchingContQ->getLength()<<endl;
                        //EV<<"--------------------------------------------------------------------------------"<<endl;
                        } // end 2.1.2
                    }
                    // Case 2.2: More Than One Job in Queue
                    else
                    {
                        //cQueue::Iterator currentIter =  cQueue::Iterator (* itt->SwitchingContQ, 0);
                        cQueue::Iterator nextIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                        nextIter++;
                        SwitchingCont * SWCN;
                        bool exit = false;


                            SWC = (  SwitchingCont *) currentIter();
                            SWCN = (  SwitchingCont *) nextIter();

                            if (sw->getStartHoldingTime() < SWC->getStartHoldingTime())// && sw->getStartHoldingTime()< SWCN->getStartHoldingTime())
                            {
                                itt->SwitchingContQ.insertBefore(currentIter.operator ()(),sw);
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
                                    SWC = (  SwitchingCont *) currentIter();
                                    SWCN = (  SwitchingCont *) nextIter();
                                if(nextIter.end()==true)
                                {
                                itt->SwitchingContQ.insertAfter(currentIter.operator ()(),sw);
                                exit = true;
                                }
                                else if (sw->getStartHoldingTime()<SWCN->getStartHoldingTime())
                                {
                                itt->SwitchingContQ.insertBefore(nextIter.operator ()(),sw);
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
            } // end of Module Name True
       } // end of Iterator for
    Ocontroller::printSWCQueue(moduleName);


} // end of insertMethod

void Ocontroller::printSWCQueue(string moduleName)
{
    int counter =0;

    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    for (itt = iStart ; itt != iEnd ; itt++)
       {
            if ( itt->getModuleName()==moduleName)
            {
                cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                SwitchingCont * SWC;// = (  SwitchingCont *) currentIter();
                EV<<"=============================="<<endl;
                EV<<"Module ( "<<moduleName<<" )"<<endl;
                EV<<"Length = "<<itt->SwitchingContQ.getLength()<<endl;
                EV<<"=============================="<<endl;

                for (currentIter; currentIter.end()==false;currentIter++)
                {
                    SWC = (  SwitchingCont *) currentIter();

                    EV<<"Job # "<<counter+1<<"-----------------"<<endl;
                    EV<<"Start Holding Time  = "<<SWC->getStartHoldingTime()<<endl;
                    EV<<"Switching State     = "<<SWC->getSwitchingState()<<endl;
                    EV<<"Delay               = "<<SWC->getDelay()<<endl;
                    EV<<"Release Time        = "<<SWC->getReleaseTime()<<endl;
                    EV<<"Target Module       = "<<SWC->getTargetModule()<<endl;
                    counter++;
                }

            }
        }
}

int Ocontroller::getNumOfOfdlStages() const {
    return numOfOFDLStages;
}

void Ocontroller::setNumOfOfdlStages(int numOfOfdlStages) {
    numOfOFDLStages = numOfOfdlStages;
}


/*void Ocontroller::setOFDLBusyMatrix() {

    const int numTS =Ocontroller::getNumTimeslots();
    const int numOfStages =Ocontroller::getNumOfOfdlStages();
    OFDLBusyMatrix  = new bool *[numTS];
    for (int i=0;i<numTS;i++)
        {
        OFDLBusyMatrix[i]=new bool [numOfStages];
        }
    // Insitilize Matrix to idle
    for (int i=0;i<numTS;i++)
        {
            EV<<" Row Index "<<i<<'\t';
        for (int j=0;j<numOfStages;j++)
        {
            OFDLBusyMatrix[i][j]=false;
            EV<<OFDLBusyMatrix[i][j]<<'\t';
        }
        EV<<endl;
        }
}*/

/*bool Ocontroller::getOFDLBusyMatrix(int row, int stage)
{

    return OFDLBusyMatrix [row][stage];
}*/

/*void Ocontroller::setDelayStages()
{
    const int maximumDelay = Ocontroller::getMaximumDelay()+1;
    const int ofdlNumberOfStage = Ocontroller::getNumOfOfdlStages();
    int devider = 1;

    this->delayStages  = new bool *[maximumDelay];
    for (int i=0;i<maximumDelay;i++)
        {
        delayStages[i]=new bool[ofdlNumberOfStage];
        }


    for (int x = 0; x < ofdlNumberOfStage;x++) // column traversal (only splitters
{
            for (int y=0;y<maximumDelay-devider; y=y+(2*devider)) // add values to columns
            {
                for(int i=y;i<y+devider;i++)
                {
                    delayStages[x][i] = false;
                    delayStages[x][i+devider] = true;
                }

            }
            devider = devider*2;
}



for (int y=0;y<maximumDelay;y++)
{
    EV<<"Delay "<<y<<'\t'<<'\t';

    for (int x=0;x<ofdlNumberOfStage;x++)
    {
        EV<<delayStages[x][y]<<'\t';

    }
    EV<<endl;

}



}*/

/*void Ocontroller::reserveOFDLStage(int row,int delay)
{

    EV<<"Inside Reserve OFDL, Delay = "<<delay<<" ,and row = "<<row<<endl;
    int stageValue = 0;

    for (int i=0;i<Ocontroller::getNumOfOfdlStages();i++)
    {
        stageValue =  this->delayStages[i][delay]*pow(2,i);
        if (stageValue !=0)
        {

            for (int i=stageValue-1; i<stageValue-1+stageValue; i++)
            {
                Ocontroller::setModuleBusyStateByName(Ocontroller::getOFDLNames(row, i));
                EV<<"Reseve Module  "<<Ocontroller::getOFDLNames(row, i)<<" for delay "<<delay<<endl;
            }

        }

    }

}*/

void Ocontroller::setModuleBusyStateByName(string moduleName)
{
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
       {
           if ( itt->getModuleName()==moduleName)
               {
               itt->setBusy();
               }// end of IF moduleType
       }
}

bool Ocontroller::OFDLStageIsBusy(int row, int stageIndex)
{

}

void Ocontroller::computeNumberOFDLs(int numOfOfdlStages)
{
    EV<<"Number of OFDLs in Path are ... ";
    for (int i=0; i<numOfOfdlStages; i++)
    {
     this->numOfOfdls+=pow(2,i);
     //EV<<"2^"<<i<<"+ ";
    }
    EV<<this->numOfOfdls<<endl;

}

/*string Ocontroller::getOFDLNames(int x, int y)
{
    return this->OFDLNames[x][y];
}*/

/*void Ocontroller::setOFDLNames()
{
    // Building OFDLNames
    const int numTS =Ocontroller::getNumTimeslots();
    const int numOFDL =Ocontroller::getNumOfOfdls();
    OFDLNames  = new string *[numTS];
    for (int i=0;i<numTS;i++)
        {
            OFDLNames[i]=new string [numOFDL];
        }


    int row = 0;
    int column = 0;

    string currentModuleName;
    ModuleInfo * currentModulePointer;
    int currentModuleID;

    string nextModuleName;
    ModuleInfo * nextModulePointer;
    int nextModuleID;




    do
    {
        int start= Ocontroller::getNumOfOsplitterStages()-1;
        //EV<<" *** Start counter ="<<start<<endl;
        int end = Ocontroller::getNumberOfSwitchesInPath()-Ocontroller::getNumOfOcombinerStages();
        //EV<<" *** End counter ="<<end<<endl;

        for (start; start < end; start++)
        {
            currentModuleName = Ocontroller::getPathNames(row,start);
            currentModuleID = Ocontroller::getModuleIDByName(currentModuleName);
            currentModulePointer = Ocontroller::getModulePointer(currentModuleID);
            //EV<<"Current Module Name is "<<currentModuleName<<" Current Module ID is "<<currentModuleID<<endl;

            nextModulePointer = currentModulePointer->getNextModuleAtGate0();
            nextModuleName = nextModulePointer->getModuleName();
            //EV<<"Next Module Name is "<<nextModuleName<<endl;

            do
            {



                this->OFDLNames[row][column] = nextModuleName;
                //EV<<"OFDLName ["<<row<<"]["<<column<<"] = "<< OFDLNames[row][column]<<endl;

                currentModuleName = nextModuleName;
                currentModuleID = Ocontroller::getModuleIDByName(currentModuleName);
                currentModulePointer = Ocontroller::getModulePointer(currentModuleID);
               // EV<<"&&& New Current Module Name is "<<currentModuleName<<" Current Module ID is "<<currentModuleID<<endl;

                nextModulePointer = currentModulePointer->getNextModuleAtGate0();
                nextModuleName = nextModulePointer->getModuleName();
               // EV<<"Next Module Name is "<<nextModuleName<<endl;

                column++;

            }while (nextModulePointer->getModuleType()==3);

        }
        row ++;
        column = 0;


    } while (row < Ocontroller::getNumTimeslots());
   Ocontroller::printOFDLNames();

}*/

string Ocontroller::getNextModuleName(string currentModuleName)
{

    string nextModuleNameAtGate0;
    ModuleInfo *nextModuleAtGate0;


    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
       {
           if ( itt->getModuleName()==currentModuleName)
               {
                   nextModuleAtGate0= itt->getNextModuleAtGate0();
                   nextModuleNameAtGate0 = nextModuleAtGate0->getModuleName();
               } // Module Found
       }// for

return nextModuleNameAtGate0;
}

ModuleInfo* Ocontroller::getModulePointer(string moduleName)
{
    ModuleInfo *mod;
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
          {
              if ( itt->getModuleName()==moduleName)
                  {
                    mod = &*itt;


                  }// end of IF moduleType

          }
    return mod;
}

/*void Ocontroller::printOFDLNames()
{
    EV<<"Path Names Matrix *************"<<endl;
    for (int row = 0; row < Ocontroller::getNumTimeslots(); row++)
    {
        EV<<" OFDL in path "<<row<<'\t';
        for (int i = 0; i < Ocontroller::getNumOfOfdls();i++)
        {
            EV<<this->OFDLNames[row][i]<<'\t';
        }
        EV<<endl;
    }
}*/

/*void Ocontroller::changeOFDLBusyMatrix(int row, int stage, bool busy)
{
    this->OFDLBusyMatrix[row][stage] = busy;
}*/

/*bool Ocontroller::getOFDLAvailableState(int delay, int row)
{
    EV<<"Inside getOFDLAvailableState, Delay = "<<delay<<" ,and row = "<<row<<endl;
    bool OFDLInPathAvailable = true;
    int stageValue = 0;

    for (int i=0;i<Ocontroller::getNumOfOfdlStages();i++)
    {
        stageValue =  this->delayStages[i][delay]*pow(2,i);
        EV<<"Stage Value: "<<this->delayStages[i][delay]<<"* 2^"<<i<<" = "<< stageValue<<endl;
        if (stageValue !=0)
        {
            EV<<"Stage "<<i<<" is Active"<<endl;
            OFDLInPathAvailable = OFDLInPathAvailable & Ocontroller::getOFDLNamesState(stageValue-1, stageValue-1+stageValue,  row);
            EV<<"OFDLInPathAvailable "<<OFDLInPathAvailable<<endl;
        }
        else
        {
            EV<<"Stage "<<i<<" is NOT Active"<<endl;
        }

    }
    EV<<"OFDLInPathAvailable @ getOFDLAvailableState "<<OFDLInPathAvailable<<endl;

    return OFDLInPathAvailable;

}*/

/*bool Ocontroller::getOFDLNamesState(int from, int to, int row)
{
    EV<<"inside getOFDLNamesState"<<"Start from "<<from<<" End at "<<to<<" at row "<<row<<endl;
    bool OFDLInPathAvailable = true;
    for (int i=from; i<to; i++)
    {
        OFDLInPathAvailable = OFDLInPathAvailable | Ocontroller::getModuleBusyStateByName(Ocontroller::getOFDLNames(row, i));
    }

    return OFDLInPathAvailable;
    EV<<"OFDLInPathAvailable @ getOFDLNamesState"<<OFDLInPathAvailable<<endl;
}*/

int Ocontroller::getCaseIndex() const {
    return caseIndex;
}

void Ocontroller::setCaseIndex(int caseIndex) {
    this->caseIndex = caseIndex;
}

int Ocontroller::getTimeSwitchingAssignmentEven() const {
    return timeSwitchingAssignmentEven;
}

void Ocontroller::setTimeSwitchingAssignmentEven(
        int timeSwitchingAssignmentEven) {
    this->timeSwitchingAssignmentEven = timeSwitchingAssignmentEven;
}

int Ocontroller::getTimeSwitchingAssignmentOdd() const {
    return timeSwitchingAssignmentOdd;
}

void Ocontroller::setTimeSwitchingAssignmentOdd(
        int timeSwitchingAssignmentOdd) {
    this->timeSwitchingAssignmentOdd = timeSwitchingAssignmentOdd;
}

bool Ocontroller::validateSwitchingConflect(bool switchingState, string moduleName)
{
    bool switchingConflectFound = false;
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

   // EV<<" For Switching State "<<switchingState<<"  ";

    for (itt = iStart ; itt != iEnd ; ++itt)
       {
           if ( itt->getModuleName()==moduleName)
               {
                   // Queue is Empty, dafenatly no conflict
                   if (itt->SwitchingContQ.isEmpty()==true)
                   {
                       switchingConflectFound = false;
                   }

                   // Queue is NOT Empty, check for conflict
                   else
                   {
                       cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                       SwitchingCont * SWC;// = (  SwitchingCont *) currentIter();

                       for (int i=0 ; i<itt->SwitchingContQ.length(); i++)
                       {
                           SWC = (  SwitchingCont *) currentIter();

                           if (SWC->getSwitchingState()!=switchingState)
                           {
                               switchingConflectFound = true;
                             //  EV<<"@@@@@@@ Switching Conflect Found where "<<SWC->getTargetModule();

                           }
                           else
                           currentIter++;
                       }

               }// end of else NOT EMPTY
       } // Module Found
       }// for
  //  EV<<" Value Return ["<<switchingConflectFound<<"]"<<endl;

return switchingConflectFound;
}

bool Ocontroller::validateDuplicate(SwitchingCont* sw, string moduleName)
{
    EV<<" I am Here $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 1"<<endl;
    bool noDuplicateExist = true;
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();
    for (itt = iStart ; itt != iEnd ; itt++)
       {
            if ( itt->getModuleName()==moduleName)
            {
                EV<<" I am Here $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 2"<<endl;

                cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                SwitchingCont * SWC;// = (  SwitchingCont *) currentIter();

                for (int i=0 ; i<itt->SwitchingContQ.length(); i++)
                {
                    SWC = (  SwitchingCont *) currentIter();
                    if (SWC->getStartHoldingTime()==sw->getStartHoldingTime())
                    {
                        EV<<" I am Here $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 3"<<endl;
                        noDuplicateExist = false;
                        EV<<"@@@@@@@ Duplicate Exist "<<SWC->getTargetModule()<<endl;

                    }
                    else
                    {
                        EV<<" I am Here $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 4"<<endl;
                    currentIter++;
                    }

            }

          }
       }
    EV<<" Before EXIT $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ 5  "<<noDuplicateExist<<endl;
    return noDuplicateExist;

}

void Ocontroller::broadcastParameters()
{

    ParameterCont * PC = Ocontroller::genrateParCont();

    PC->setNumTimeslots(Ocontroller::getNumTimeslots());
    PC->setNumFrames(Ocontroller::getNumFrames());
    PC->setTimeslotSize(Ocontroller::getTimeslotsSize());
    PC->setDataRate(Ocontroller::getDataRate());
    PC->setTimeslotDuration(Ocontroller::getTimeslotDuration());
    PC->setGuardTime(Ocontroller::getGuardTime());
    PC->setName("broadcastParameter");
    PC->setKind(1);

    for (int i=0; i<Ocontroller::gateSize("control$o");i++)
    {
        ParameterCont * PCD =PC->dup(); //Ocontroller::genrateParCont();
        //PCD = PC->dup();
        send(PCD,"control$o",i);
    }
    delete PC;

}

/*void Ocontroller::genPermutation(int TS)
{
    const int slots=TS;
    const int TotalPermutation = Ocontroller::getNumberPermutations();
    permutation = new int[slots];

    permutationList = new int*[TotalPermutation];
    permutationList[pcounter] = new int[slots];


    for (int j = 0 ; j < slots ; j++)
    {
        permutation[j]=j;
    }

    EV<<endl;

    Ocontroller::addtoPList(pcounter,permutation);

    while(next_permutation(permutation,permutation+slots))
    {
      pcounter++;
      if (pcounter<TotalPermutation)
          Ocontroller::addtoPList(pcounter, permutation);
    }

    Ocontroller::displayPList(permutationList);



}// end of permutation*/

/*void  Ocontroller::addtoPList(int index, int *permutation)
{

    int slots = Ocontroller::getNumTimeslots();
    permutationList[index] = new int[slots];

    //cout<<"index = "<<index<<endl;
    //cout<<"slots ="<<slots<<endl;

   for( int j=0 ; j<slots; j++){
       permutationList[index][j] = permutation[j];
       //permutationFile<<permutation[j];
       //cout<<"permutationList ["<<index<<"] ["<<j<<"] "<<permutationList[index][j]<<endl;
   }
   //permutationFile<<endl;

}*/

void Ocontroller::displayPermutation(int* iarr, int numTimeslots){
    const int slots = numTimeslots;

    for(int i=0; i<slots; ++i)
        EV<<iarr[i]<<",";
    EV<<endl;
}

// ============================= EVERY THING ABOUT PATHS

void Ocontroller::setNumberOfPaths()
{
    // Total Number of Paths per delay
    numberOfPaths = new int [Ocontroller::getMaximumDelay()];
    for (int i=0;i<Ocontroller::getMaximumDelay();i++)
    {
        numberOfPaths[i]= Ocontroller::getNumTimeslots();
        /* Uncomment this section to see outputs
         * EV<<"Available paths of delay "<<i+1<<" = "<<numberOfPaths[i]<<endl;
         */

    }
    Ocontroller::setTotalNumberOfPaths();

}

int Ocontroller::getNumberOfPaths(int delay) const
{

    return numberOfPaths[delay-1];
}

void Ocontroller::setTotalNumberOfPaths()
{

    for (int i=0;i<Ocontroller::getMaximumDelay();i++)
        this->totalNumberOfPaths+= Ocontroller::getNumberOfPaths(i+1);
    //EV<<"Total Number of Paths is.. "<<totalNumberOfPaths<<endl;
}

int Ocontroller::getTotalNumberOfPaths()
{

    return this->totalNumberOfPaths;
}

// ============================= END OF PATHS

void Ocontroller::setAllNextModulesPointer() {

    int modID;
    int modType;
    list<ModuleInfo>::iterator itt;
    list<ModuleInfo>::iterator iStart = modules.begin();
    list<ModuleInfo>::iterator iEnd = modules.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
          {
                modType = itt->getModuleType();

            switch (modType)
            {
            case 0:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;
                modID = itt->getModuleID();
                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                itt->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
                //EV<<"Next Module on Gate 0 is . . "<<itt->getNextModuleAtGate0()<<endl;
                itt->setNextModuleAtGate1(NULL);
                //EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 1:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;

                                itt->setNextModuleAtGate0(NULL);
                                //EV<<"Next Module on Gate 0 is . . NULL"<<endl;
                                itt->setNextModuleAtGate1(NULL);
                                //EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 2:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;
                itt->setNextModuleAtGate0(NULL);
                //EV<<"Next Module on Gate 0 is . . NULL"<<endl;
                itt->setNextModuleAtGate1(NULL);
               // EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 3:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;
                modID = itt->getModuleID();
                                cModule * nextAtGate0Module;
                                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                                int nextAtGate0ID = nextAtGate0Module->getId();
                                itt->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
                                //EV<<"Next Module on Gate 0 is . . "<<itt->getNextModuleAtGate0()<<endl;
                                itt->setNextModuleAtGate1(NULL);
                               // EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 4:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;
                modID = itt->getModuleID();
                                cModule * nextAtGate0Module;
                                nextAtGate0Module = simulation.getModule(modID)->gate("out",0)->getNextGate()->getOwnerModule();
                                int nextAtGate0ID = nextAtGate0Module->getId();
                                itt->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
                                //EV<<"Next Module on Gate 0 is . . "<<itt->getNextModuleAtGate0()<<endl;

                                cModule * nextAtGate1Module;
                                nextAtGate1Module = simulation.getModule(modID)->gate("out",1)->getNextGate()->getOwnerModule();
                                int nextAtGate1ID = nextAtGate1Module->getId();
                                itt->setNextModuleAtGate1(Ocontroller::getModulePointer(nextAtGate1ID));
                                //EV<<"Next Module on Gate 1 is . . "<<itt->getNextModuleAtGate1()<<endl;
                                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 5:
            {
               // EV<<"Module Name... "<<itt->getModuleName()<<endl;
                modID = itt->getModuleID();
                                cModule * nextAtGate0Module;
                                nextAtGate0Module = simulation.getModule(modID)->gate("out",0)->getNextGate()->getOwnerModule();
                                int nextAtGate0ID = nextAtGate0Module->getId();
                                itt->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
                               // EV<<"Next Module on Gate 0 is . . "<<itt->getNextModuleAtGate0()<<endl;

                                cModule * nextAtGate1Module;
                                nextAtGate1Module = simulation.getModule(modID)->gate("out",1)->getNextGate()->getOwnerModule();
                                int nextAtGate1ID = nextAtGate1Module->getId();
                                itt->setNextModuleAtGate1(Ocontroller::getModulePointer(nextAtGate1ID));
                                //EV<<"Next Module on Gate 1 is . . "<<itt->getNextModuleAtGate1()<<endl;
                                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 6:
            {
                //EV<<"Module Name... "<<itt->getModuleName()<<endl;
                modID = itt->getModuleID();
                                cModule * nextAtGate0Module;
                                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                                int nextAtGate0ID = nextAtGate0Module->getId();
                                itt->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
                              //  EV<<"Next Module on Gate 0 is . . "<<itt->getNextModuleAtGate0()<<endl;
                                itt->setNextModuleAtGate1(NULL);
                              //  EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            default:
               // EV<<"Class not found"<<endl;
                break;


            }// end switch

          }//end of for

}

void Ocontroller::setNextModulePointer(ModuleInfo *modi)
{

    int modID = modi->getModuleID();
    int modType = modi->getModuleType();


            switch (modType)
            {
            case 0:
            {
                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                modi->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
              //  EV<<"Next Module on Gate 0 is . . "<<modi->getNextModuleAtGate0()<<endl;
                modi->setNextModuleAtGate1(NULL);
              //  EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 1:
            {


                modi->setNextModuleAtGate0(NULL);
               // EV<<"Next Module on Gate 0 is . . NULL"<<endl;
                modi->setNextModuleAtGate1(NULL);
              //  EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 2:
            {

                modi->setNextModuleAtGate0(NULL);
              //  EV<<"Next Module on Gate 0 is . . NULL"<<endl;
                modi->setNextModuleAtGate1(NULL);
                //EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 3:
            {

                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                modi->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
              //  EV<<"Next Module on Gate 0 is . . "<<modi->getNextModuleAtGate0()<<endl;
                modi->setNextModuleAtGate1(NULL);
             //   EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 4:
            {

                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out",0)->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                modi->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
              //  EV<<"Next Module on Gate 0 is . . "<<modi->getNextModuleAtGate0()<<endl;

                cModule * nextAtGate1Module;
                nextAtGate1Module = simulation.getModule(modID)->gate("out",1)->getNextGate()->getOwnerModule();
                int nextAtGate1ID = nextAtGate1Module->getId();
                modi->setNextModuleAtGate1(Ocontroller::getModulePointer(nextAtGate1ID));
              //  EV<<"Next Module on Gate 1 is . . "<<modi->getNextModuleAtGate1()<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 5:
            {

                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out",0)->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                modi->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
            //    EV<<"Next Module on Gate 0 is . . "<<modi->getNextModuleAtGate0()<<endl;

                cModule * nextAtGate1Module;
                nextAtGate1Module = simulation.getModule(modID)->gate("out",1)->getNextGate()->getOwnerModule();
                int nextAtGate1ID = nextAtGate1Module->getId();
                modi->setNextModuleAtGate1(Ocontroller::getModulePointer(nextAtGate1ID));
             //   EV<<"Next Module on Gate 1 is . . "<<modi->getNextModuleAtGate1()<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            case 6:
            {

                cModule * nextAtGate0Module;
                nextAtGate0Module = simulation.getModule(modID)->gate("out")->getNextGate()->getOwnerModule();
                int nextAtGate0ID = nextAtGate0Module->getId();
                modi->setNextModuleAtGate0(Ocontroller::getModulePointer(nextAtGate0ID));
               // EV<<"Next Module on Gate 0 is . . "<<modi->getNextModuleAtGate0()<<endl;
                modi->setNextModuleAtGate1(NULL);
               // EV<<"Next Module on Gate 1 is . . NULL"<<endl;
                EV<<"Next Module Pointer was set successfully"<<endl;

            }
            break;
            default:
              //  EV<<"Class not found"<<endl;
                break;


            }// end switch


}

void Ocontroller::displayPList(int **permutationList)
{
    int TP = Ocontroller::getNumberPermutations();
    int TS = Ocontroller::getNumTimeslots();

    for( int j=0 ; j<TP; ++j)
    {
        EV<<"P# "<<j<<"   ";
        for( int i=0 ; i<TS; ++i)
        {
           EV<<permutationList[j][i]<<" ";
        }
    EV<<endl;

    }

}

bool Ocontroller::notXOR(bool x, bool y)
{
    return ~(( x | y ) & ~( x & y ));

}

bool Ocontroller::validateConflect(simtime_t startHoldingTime,string moduleName, bool switchingState)
{
        bool conflectFound = false;

        list<ModuleInfo>::iterator itt;
        list<ModuleInfo>::iterator iStart = modules.begin();
        list<ModuleInfo>::iterator iEnd = modules.end();

        //EV<<"Validate Conflect module( "<< moduleName << " )For Start Holding Time "<<startHoldingTime<<" ";

        for (itt = iStart ; itt != iEnd ; ++itt)
           {
               if ( itt->getModuleName()==moduleName)
                   {
                       // Queue is Empty, dafenatly no conflict
                       if (itt->SwitchingContQ.isEmpty()==true)
                       {
                           conflectFound = false;
                       }

                       // Queue is NOT Empty, check for conflict
                       else
                       {
                           cQueue::Iterator currentIter =  cQueue::Iterator ( itt->SwitchingContQ, 0);
                           SwitchingCont * SWC;// = (  SwitchingCont *) currentIter();

                           for (int i=0 ; i<itt->SwitchingContQ.length(); i++)
                           {
                               SWC = (  SwitchingCont *) currentIter();

                               if (SWC->getStartHoldingTime()==startHoldingTime)
                               {
                                   if (SWC->getSwitchingState()!= switchingState)
                                   conflectFound = true;
                                   //EV<<"@@@@@@@ Conflect Found where "<<SWC->getTargetModule();
                                   else
                                       conflectFound = false;

                               }
                               else
                               currentIter++;
                           }

                   }// end of else NOT EMPTY
           } // Module Found
           }// for
        //EV<<" Value Return ["<<conflectFound<<"]";

    return conflectFound;
}



}//end of namespace
