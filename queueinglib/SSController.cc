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
    this->frameCounter = 0;
    this->timeslotCounter = 0;
    this->evenTimeslotAssignment = par ("switchingAssignmentEven");
    this->oddTimeslotAssignment = par("switchingAssignmentOdd");
    P3DControllerEvent = new cMessage();
    P3DControllerEvent->setKind(1);

    SSController::broadcastParameter();

        const int numTS = this->numberOfTimeslots;
        const int numSWinPath =6;
        pathNames  = new string *[numTS];
        for (int i=0;i<numTS;i++)
            {
            pathNames[i]=new string [numSWinPath];
            }
                           // Deley 0 and 1
                           pathNames [0][0]="ssSplitter0";
                           pathNames [0][1]="ssSplitter1";
                           pathNames [0][2]="ssSplitter3";
                           pathNames [0][3]="ssCombiner3";
                           pathNames [0][4]="ssCombiner1";
                           pathNames [0][5]="ssCombiner0";

                           // Deley 2 and 3
                           pathNames [1][0]="ssSplitter0";
                           pathNames [1][1]="ssSplitter1";
                           pathNames [1][2]="ssSplitter4";
                           pathNames [1][3]="ssCombiner4";
                           pathNames [1][4]="ssCombiner1";
                           pathNames [1][5]="ssCombiner0";

                           // Deley 4 and 5
                           pathNames [2][0]="ssSplitter0";
                           pathNames [2][1]="ssSplitter2";
                           pathNames [2][2]="ssSplitter5";
                           pathNames [2][3]="ssCombiner5";
                           pathNames [2][4]="ssCombiner2";
                           pathNames [2][5]="ssCombiner0";

                           // Deley 6 and 7
                           pathNames [3][0]="ssSplitter0";
                           pathNames [3][1]="ssSplitter2";
                           pathNames [3][2]="ssSplitter6";
                           pathNames [3][3]="ssCombiner6";
                           pathNames [3][4]="ssCombiner2";
                           pathNames [3][5]="ssCombiner0";

    SSController::setDelayMatrix();
    scheduleAt(1, P3DControllerEvent);
}

void SSController::handleMessage(cMessage *msg)
{


    if (msg->getKind()==1) // events
    {
        EV<<"Frame Counter is "<<this->frameCounter<<" --Number of frames "<<this->numberOfFrames<<endl;
        EV<<"Timeslot Counter is "<<this->timeslotCounter<<" --Number of timeslots "<<this->numberOfTimeslots<<endl;
        if(this->frameCounter < this->numberOfFrames && this->timeslotCounter < this->numberOfTimeslots)
        {
        int inTS;
        int outTS;
        int pathIndex;
        int PathNamesIndex;
        int delay;
        int SWAssingment;

       inTS = this->timeslotCounter;

       if(this->frameCounter%2==0)
       {
           SWAssingment = this->evenTimeslotAssignment;
       }
       else
       {
           SWAssingment = this->oddTimeslotAssignment;

       }

       outTS = SSController::getOutputTimeslot(SWAssingment+1, inTS+1);
       EV<<"Current Timeslot @ Controller is . . . "<< inTS<<endl;
       EV<<"Current Frame @ Controller is . . . "<< this->frameCounter<<endl;
       EV<<"output switching for TS "<< inTS<< "is . . ."<<outTS<<endl;
       delay = SSController::computeDelay(inTS,outTS);
       EV<<"required delay for switching TS "<< inTS<< " to "<<outTS<< " is . . . "<<delay<<endl;
       this->timeslotCounter++;
       if (this->timeslotCounter >= numberOfTimeslots)
       {
           this->frameCounter++;
           this->timeslotCounter = 0;
       }
       pathIndex= delay;
       EV<<"Path Index  "<<pathIndex<<endl;
       //SSController::printSwitchList();
       SSController::reservePath(pathIndex, delay);
       SSController::sendSWC();
       scheduleAt(simTime()+timeslotDuration, P3DControllerEvent);

        }
        else
        {   EV<<"I am here ....1 "<<endl;
            if (SSController::allSWCQEmpty()==false)
           {
                EV<<"I am here ....2 "<<endl;
                SSController::sendSWC();
               scheduleAt(simTime()+timeslotDuration, P3DControllerEvent);
               this->timeslotCounter++;

           }
            else
                {
                EV<<"I am here ....3 "<<endl;
                SSController::finish();
                }


        }

    }
    if (msg->getKind()==2)
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
                   for (int i=0;i<SSController::gateSize("control$o");i++)
                       {
                           cGate * outputGate = SSController::gate("control$o",i);
                           if (outputGate->getNextGate()== simulation.getModule(mod.getModuleId())->gate("control$i"))
                               mod.setContOutputPortId(outputGate->getId());
                       }
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
                   for (int i=0;i<SSController::gateSize("control$o");i++)
                       {
                           cGate * outputGate = SSController::gate("control$o",i);
                           if (outputGate->getNextGate()== simulation.getModule(mod.getModuleId())->gate("control$i"))
                               mod.setContOutputPortId(outputGate->getId());
                       }
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
                   for (int i=0;i<SSController::gateSize("control$o");i++)
                       {
                           cGate * outputGate = SSController::gate("control$o",i);
                           if (outputGate->getNextGate()== simulation.getModule(mod.getModuleId())->gate("control$i"))
                               mod.setContOutputPortId(outputGate->getId());
                       }
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
                   for (int i=0;i<SSController::gateSize("control$o");i++)
                       {
                           cGate * outputGate = SSController::gate("control$o",i);
                           if (outputGate->getNextGate()== simulation.getModule(mod.getModuleId())->gate("control$i"))
                               mod.setContOutputPortId(outputGate->getId());
                       }
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
                   for (int i=0;i<SSController::gateSize("control$o");i++)
                       {
                           cGate * outputGate = SSController::gate("control$o",i);
                           if (outputGate->getNextGate()== simulation.getModule(mod.getModuleId())->gate("control$i"))
                               mod.setContOutputPortId(outputGate->getId());
                       }
                   switchesList.push_back(mod);
                   delete msg;
                   bubble ("Combiner added");
               }
                   break;
               }


        }

}

void SSController::broadcastParameter() {

    BC = new P3DBroadcastParameter();
    BC->setKind(3);
    BC->setName("Broadcast");
    BC->setNumberOfTimeslots(this->numberOfTimeslots);
    BC->setNumberOfFrames(this->numberOfFrames);
    BC->setTimeslotDuration(this->timeslotCounter);
    BC->setTimeslotDuration(this->timeslotDuration);
    BC->setGuardTime(this->guardTime);


    for (int i=0; i<SSController::gateSize("control$o");i++)
        {
        P3DBroadcastParameter * BCP = BC->dup();
            send(BCP,"control$o",i);
        }
        delete BC;
}

int SSController::getOutputTimeslot(int row, int column)
{
    int result = -1, rowIndex = 0;
    string temp;
    ifstream inFile;

            if(row > 0 && column > 0)
            {
             inFile.open("permutation4.txt");

             for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
              inFile>>temp;

             inFile.close();

             if(rowIndex>=row && column<=temp.size())
              result = temp.at(column - 1) - '0';
            }

 return result;
}

int SSController::computeDelay(int in, int out)
{
    int delay=0;
    delay = numberOfTimeslots+out-in;
    return delay;
}

void SSController::reservePath(int pathIndex, int delay) {
    list<P3DModuleDB>::iterator itt;
    list<P3DModuleDB>::iterator iStart = switchesList.begin();
    list<P3DModuleDB>::iterator iEnd = switchesList.end();
    string moduleName;


    EV<<"Path names index is "<<pathIndex/2<<endl;

    for (int i = 0; i< 6; i++)
    {
        moduleName = this->pathNames[pathIndex/2][i];



        for (itt = iStart ; itt != iEnd ; ++itt)
        {
            if ( itt->getModuleName()==moduleName)
                {
                itt->setBusy(true);
                EV<<"Set to busy"<<endl;
                itt->setDelay(commulatedDelayMatrix[i][delay]);
                EV<<"######### Set Comm Delay"<<commulatedDelayMatrix[i][delay]<<endl;
                bool SWCfromFile = SSController::getSWC(pathIndex+1,i+1);
                EV<<"SWC from file is "<<SWCfromFile<<"  ";
                SSSwitchingCont * SWCont = genrateSWCont();
                SWCont->setSwitchingState(SWCfromFile);
                SWCont->setKind(4);
                SWCont->setName("SWCM");
                SWCont->setOutputPortIndex(itt->getContOutputPortId());
                SWCont->setDelay(commulatedDelayMatrix[i][delay]);
                SWCont->setTargetModuleID(itt->getModuleId());
                SWCont->setStartHoldingTime(simTime()+commulatedDelayMatrix[i][delay]*this->timeslotDuration);
                SWCont->setReleaseTime(simTime()+commulatedDelayMatrix[i][delay]*this->timeslotDuration+this->guardTime);
                SWCont->setTargetModule(itt->getModuleName().c_str());

                itt->insertOrderedSWC(SWCont);


               // itt->printSwitcchingContQ();






                }

        }
    }




}

void SSController::setDelayMatrix()
{

    // Building Delay Matrix.
       const int MaximumDelayPlus1 = 8;
       const int numSWPerPath = 6;
       this->commulatedDelayMatrix = new int *[numSWPerPath];


       for (int i=0;i<numSWPerPath;i++)
           commulatedDelayMatrix[i]=new int[MaximumDelayPlus1];

       // Setting up the Splitters columns ( No delay )

       for (int sp=0; sp<3;sp++)
       {
           for (int s=0; s<MaximumDelayPlus1;s++)
               commulatedDelayMatrix[sp][s]=0;
       }

       // Setting up Combiners

       for (int sw=3; sw<numSWPerPath;sw++)
       {
           for (int y=0;y<MaximumDelayPlus1; y++)
                  {
               commulatedDelayMatrix[sw][y] = y;
                   }

                  }//end for

       for (int i=0;i<MaximumDelayPlus1;i++)
           {
                   for (int x = 0; x <numSWPerPath; x++)
                   {

                      EV<<commulatedDelayMatrix[x][i]<<"   ";

                   }
           EV<<endl;
           }
}

int SSController::getSWC(int row, int column)
{
 int result = -1, rowIndex = 0;
 string temp;
 ifstream inFile;

     if(row > 0 && column > 0)
     {
      inFile.open("SSSWC4.txt");

      for(rowIndex = 0; inFile.good() && rowIndex < row; rowIndex++)
       inFile>>temp;

      inFile.close();

      if(rowIndex>=row && column<=temp.size())
       result = temp.at(column - 1) - '0';
     }

 return result;
}

void SSController::sendSWC() {

    list<P3DModuleDB>::iterator itt;
    list<P3DModuleDB>::iterator iStart = switchesList.begin();
    list<P3DModuleDB>::iterator iEnd = switchesList.end();
    int outputGateID;
    for (itt = iStart ; itt != iEnd ; ++itt)
       {
        SSSwitchingCont * SWCX = itt->getSWC();
        if (SWCX !=NULL)
            {
            outputGateID = itt->getContOutputPortId();
            send (SWCX,outputGateID);


            }
        else
            EV<<"NULL return "<<endl;

       }




}

void SSController::printSwitchList() {

    list<P3DModuleDB>::iterator itt;
    list<P3DModuleDB>::iterator iStart = switchesList.begin();
    list<P3DModuleDB>::iterator iEnd = switchesList.end();

    for (itt = iStart ; itt != iEnd ; ++itt)
       {
        EV<<"Module Name : "<<itt->getModuleName()<<endl;
        EV<<"Module ID : "<<itt->getModuleId()<<endl;
        EV<<"Module OutputID : "<<itt->getContOutputPortId()<<endl;
        EV<<"=================== "<<endl;
       }
}

bool SSController::allSWCQEmpty() {
    bool allEmpty;
    int sum=0;
    list<P3DModuleDB>::iterator itt;
    list<P3DModuleDB>::iterator iStart = switchesList.begin();
    list<P3DModuleDB>::iterator iEnd = switchesList.end();

       for (itt = iStart ; itt != iEnd ; ++itt)
          {
           sum+= itt->getQueueLength();
          }
       if (sum==0)
           return true;
       else
           return false;


}

SSController::~SSController() {
    cancelAndDelete (BC);
    cancelAndDelete (P3DControllerEvent);
    for (int i=0;i<6;i++)
        {

        delete []commulatedDelayMatrix[i];
        }
    delete[] commulatedDelayMatrix;
        list<P3DModuleDB>::iterator it;
       list<P3DModuleDB>::iterator iStart = switchesList.begin();
       list<P3DModuleDB>::iterator iEnd = switchesList.end();
       switchesList.erase(iStart,iEnd);


}

SSSwitchingCont * SSController::genrateSWCont()
{
    SSSwitchingCont *SWCont = new SSSwitchingCont();
    return SWCont;

}

} //namespace
