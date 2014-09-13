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
#include "Osource.h"
#include "ModuleInfo.h"
#include "contFrame_m.h"
#include "SyncFrame_m.h"
#include "switchingCont_m.h"
#include "ParameterCont_m.h"
#include "releaseOFDL_m.h"
#include <cmodule.h>
#include <list>
#include <cproperty.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdlib.h>


namespace queueing {

#ifndef OCONTROLLER_H_
#define OCONTROLLER_H_

using namespace std;

class Ocontroller : public cSimpleModule {
private:
    /*cModule * osourcePointer;
    cModule * osinkPointer;
    cModule * ocontrollerPointer;*/
    cModule * oFDLPointer;
    /*cModule * oswitchPointer;
    cModule * osplitterPointer;
    cModule * ocombinerPointer;*/

    int numParametersOFDL;
    int numParametersOswitch;
    int numParametersOsplitter;
    int numParametersOcombiner;

    int numOfOsplitters;
    int numOfOcombiners;
    int numOfOswitches;
    int numOfOfdls;

    int numOfOswitchStages;
    int numOfOsplitterStages;
    int numOfOcombinerStages;
    int numOfOFDLStages;
    int numberOfSwitchesInPath;

    // Parameters
    int numTimeslots;
    int timeslotSize;
    int numFrames;
    double dataRate;
    double timeslotDuration;
    double guardTime;
    double interArrivalTime;
    int caseIndex;

    //ParameterCont *parCont;
    //SwitchingCont *SWCont;
    //ContFrame *cont;

    int totalChannels;
    int timeslotCounter;
    int frameCounter;
    int nextTimeslotScheduled;
    int nextFrameScheduled;
    int currentTimeslotScheduled;
    int currentFrameScheduled;

    //test switching
    //string * moduleNames;
    //bool  **switchingControl;
    string **pathNames;
    //string **OFDLNames;
    //bool **OFDLBusyMatrix;
    int **delayMatrix;
    int **commulatedDelayMatrix;
    //bool **delayStages;

    int SCCounter;
    int tracktimeslot;

    int maximumDelay;
    //double *FDL;
    int numJobs;
    int jobCounter;

    simtime_t startTime;

    cMessage * event;
    cMessage * broadcastParameter;
    cMessage * OFDLMessage;
    cMessage * releaseOFDLBusyState;


    int timeSwitchingAssignment;
    int timeSwitchingAssignmentOdd;
    int timeSwitchingAssignmentEven;

public:
    list <ModuleInfo> modules;
    //list <Paths> allPaths;

    int totalPermutations;
    //int *permutation;               // permutation assignment
    //int **permutationList;          // list of all permutations
    int pcounter;
    ofstream permutationFile;
    ofstream SWCFile;
    int *numberOfPaths;
    int totalNumberOfPaths;

    Osource* mySRC;

    Ocontroller();
    virtual ~Ocontroller();
    int getNumberFromFile(int row, int column);
    int getSWCFromFile(int row, int column);

    //setters
    void setNumTimeslots(int numTS);
    void setTimeslotsSize(int TSSize);
    void setNumFrames(int Frames);
    void setDataRate(double DR);
    void setTimeslotDuration(int timeslotSize, double dataRate);
    void setInterArrivalTime();
    void setNumParametersOFDL (int P);
    void setNumParametersOswitch (int P);
    void setNumParametersOsplitter (int P);
    void setNumParametersOcombiner (int P);
    void setNumOfOsplitters(int numOfOsplitters);
    void setNumOfOcombiners(int numOfOcombiners);
    void setNumOfOswtiches(int numOfOswitces);
    void setNumOfOfdls(int numOfOfdls) ;
    void setFrameCounter(int frameCounter);
    void setTimeslotCounter(int timeslotCounter);
    void setNumberPermutations(int TS);
    void setTimeSwitchingAssignment(int timeSwitchingAssignment);
    void setTimeSwitchingAssingmentIndexerx(int timeSwitchingAssingmentIndexerx);
    void setGuardTime(double timeslotDuration);
    void setNumberOfPaths();
   // void setAllPath();
    void setMaximumDelay(int TS);
    void setTotalNumberOfPaths();
    //void setSwitchingControl();
    void setDelayMatrix();
    double myAbs(double x);


    //getters
    int getNumTimeslots();
    int getTimeslotsSize();
    int getNumFrames();
    int getDataRate();
    double getTimeslotDuration();
    double getInterArrivalTime();
    int getNumParametersOFDL ();
    int getNumParametersOswitch ();
    int getNumParametersOsplitter ();
    int getNumParametersOcombiner ();
    int getModuleOutputID(int moduleID);
    int getNumOfOsplitters();
    int getNumOfOcombiners();
    int getNumOfOswtiches();
    int getNumOfOfdls();
    int getFrameCounter() const;
    int getTimeslotCounter() const;
    int getNumberPermutations();
    int getTimeSwitchingAssignment() const;
    int getTimeSwitchingAssingmentIndexerx() const;
    double getGuardTime() const;
    int getMaximumDelay() const;
    int getNumberOfPaths(int delay) const;
    int getTotalNumberOfPaths();
    int getNumOfOcombinerStages() const;
    void setNumOfOcombinerStages(int numOfOcombinerStages);
    int getNumOfOsplitterStages() const;
    void setNumOfOsplitterStages(int numOfOsplitterStages);
    int getNumOfOswitchStages() const;
    void setNumOfOswitchStages(int numOfOswitcheStages);
    int getNumberOfSwitchesInPath() const;
    void setNumberOfSwitchesInPath();
    string getPathNames(int x, int y) ;
    //string getOFDLNames(int x, int y) ;
    void setPathNames();
    //void setOFDLNames();
    bool getSwitchingControl(int x, int y);
    int getPathNamesIndex(int SWCIndex);
    bool notXOR(bool x, bool y);
    int getNumOfOfdlStages() const;
    void setNumOfOfdlStages(int numOfOfdlStages);
    //void setOFDLBusyMatrix();
    //bool getOFDLBusyMatrix( int row, int stage);
    //void changeOFDLBusyMatrix (int row, int stage, bool busy);
    void setDelayStages();
    int computeDelayFromDelayMatrix();
    void computeNumberOFDLs(int numOfOfdlStages);
    //bool getOFDLAvailableState(int delay, int row);
    //bool getOFDLNamesState (int from, int to, int row);
    int getCaseIndex() const;
    void setCaseIndex(int caseIndex);
    int getTimeSwitchingAssignmentEven() const;
    void setTimeSwitchingAssignmentEven(int timeSwitchingAssignmentEven);
    int getTimeSwitchingAssignmentOdd() const;
    void setTimeSwitchingAssignmentOdd(int timeSwitchingAssignmentOdd);

protected:
    // Messages and Frames
    ContFrame *genrateCont();
    SwitchingCont *genrateSWCont();
    ParameterCont * genrateParCont();

    // Module Info Related
        int getModuleIDByName(string moduleName);
       void setAllNextModulesPointer();
       ModuleInfo * getModulePointer(int modID);
       ModuleInfo * getModulePointer(string moduleName);
       void setNextModulePointer(ModuleInfo *modi) ;
       bool getModuleSwitchingStateByName(string moduleName);
       bool getModuleBusyStateByName(string moduleName);
       void setModuleBusyStateByName(string moduleName);
       bool validateConflect (simtime_t startHoldingTime, string moduleName,bool switchingState);
       bool validateDuplicate (SwitchingCont * sw, string moduleName);
       bool validateSwitchingConflect (bool switchingState, string moduleName);
       bool queueIsEmpty(string moduleName);
       bool allSWCQEmpty();
       void  insertSWCInOrder(SwitchingCont * sw, string moduleName );
       void printSWCQueue(string moduleName);
       string getNextModuleName(string currentModuleName);
       void printOFDLNames();


    // Operations
    void increaseFrameCounter();
    void increaseTimeslotCounter();
    void initialize();
    void handleMessage(cMessage *msg);
    void buildFDL();
    void sendSwitchingCont(int pathNamesIndex, int SWCIndex, int delay);
    void sendSwitchingCont();
    int computeDelay (int in, int out);
    void computeOswitchStages(int TS);
    void computeOsplitterStages(int TS);
    void computeOcombinerStages(int TS);
    void increaseNumOfOsplitters();
    void increaseNumOfOcombiners();
    void increaseNumOfOswitches();
    void increaseNumOfOfdls() ;
    void setOFDLDelay();

    int selectPath(int delay);
    void reservePath (int pathNamesIndex,int pathIndex, int delay);
   // void reserveOFDLStage(int row, int delay);
    bool OFDLStageIsBusy(int row, int stageIndex);
    void releaseOFDLStage (int row, int stageIndex);

    // Permutations
    //void genPermutation(int TS);
    void addtoPList(int index,int *permutation);
    void displayPermutation(int* iarr, int X);
    void displayPList(int **permutationList);


    virtual void broadcastParameters();

};

}// end of namespace



#endif /* OCONTROLLER_H_ */
