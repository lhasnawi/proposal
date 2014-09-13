/*
 * ModuleInfo.h
 *
 *  Created on: Apr 14, 2013
 *      Author: Luai
 */

#include <omnetpp.h>
#include <iostream>
#include "switchingCont_m.h"
//#include <string.h>

#ifndef MODULEINFO_H_
#define MODULEINFO_H_
using namespace std;

namespace queueing {

class ModuleInfo {
public:

    static int moduleCounter;
    int frameType;
    string moduleName;
    int moduleID;
    int moduleType;
    int ControllerInputGateID;
    int ControllerOutputGateID;
   ModuleInfo * nextModuleAtGate0; // UpperGate (equivalent to left)
   ModuleInfo * nextModuleAtGate1; // LowerGate (equivalent to Right)
   bool available;
   bool barState;
   simtime_t startHoldingTime;
   simtime_t releaseHoldingTime;
   int delay;
   cQueue SwitchingContQ;



    ModuleInfo();
    virtual ~ModuleInfo();

    //Setters

     void setFrameType(int FT);
     void setModuleName(string MN);
     void setModuleID(int MI);
     void setModuleType(int MT);
     void setControllerInputGateID(int CIGID); // Controller input gate is connected to this module at gate ID
     void setControllerOutputGateID(int COGID);
     void setNextModuleAtGate0( ModuleInfo * m);
     void setNextModuleAtGate1( ModuleInfo * m);

    // Getters
     int getModuleCounter();
     int getFrameType();
     string getModuleName();
     int getModuleID();
     int getModuleID(string moduleName);
     int getModuleType();
     int getControllerInputGateID();
     int getControllerOutputGateID();

     ModuleInfo*& getNextModuleAtGate0() ;
     ModuleInfo*& getNextModuleAtGate1() ;
     ModuleInfo* getNextModuletest();
    bool isBusy();
    void setBusy();
    void setFree();
    bool isBar();
    void setBar();
    void setCross();
    const simtime_t& getReleaseHoldingTime() const;
    void setReleaseHoldingTime(const simtime_t& releaseHoldingTime);
    const simtime_t& getStartHoldingTime() const;
    void setStartHoldingTime(const simtime_t& startHoldingTime);
    int getDelay() const;
    void setDelay(int delay);
    void insertInOrder(SwitchingCont * sw);
    bool validateConflect (int delay);
    bool queueIsEmpty();
};




} /* namespace queueing */
#endif /* MODULEINFO_H_ */
