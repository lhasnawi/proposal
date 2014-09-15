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

#ifndef __QUEUEINGLIB_SWITCH3D_H_
#define __QUEUEINGLIB_SWITCH3D_H_

#include <omnetpp.h>
#include <cmodule.h>
#include "contFrame_m.h"
#include "switchingCont_m.h"
#include "ParameterCont_m.h"
#include "Oframe_m.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ModuleInfo.h"
#include "Ocontroller.h"

namespace queueing {

/**
 * TODO - Generated class
 */
class Switch3D : public cSimpleModule
{
private:
   bool barState;           // bar state -> True;  Cross state -> False
   simtime_t startHolding;
   simtime_t releaseTime;
   cMessage *releaseMessage;

   int numTimeslots;
   int timeslotSize;
   int numFrames;
   double dataRate;
   simtime_t timeslotDuration;
   double guardTime;
   ContFrame *cont;


public:
   Ocontroller* myCtl;
   Switch3D();
   virtual ~Switch3D();
   virtual void switchToCross();
   virtual void switchToBar();
   virtual bool getSwitchState();
    double getDataRate() const;
    void setDataRate(double dataRate);
    double getGuardTime() const;
    void setGuardTime(double guardTime);
    int getNumFrames() const;
    void setNumFrames(int numFrames);
    int getNumTimeslots() const;
    void setNumTimeslots(int numTimeslots);
    simtime_t getTimeslotDuration() ;
    void setTimeslotDuration(simtime_t timeslotDuration);
    int getTimeslotSize() const;
    void setTimeslotSize(int timeslotSize);
    void setModuleBusyStateTo(string moduleName, bool availableState);
    bool getModuleBusyStateTo(string moduleName);
    const simtime_t& getReleaseTime() const;
    void setReleaseTime(const simtime_t& releaseTime);
    const simtime_t& getStartHolding() const;
    void setStartHolding(const simtime_t& startHolding);

protected:
   virtual ContFrame *genrateCont();
   virtual void initialize();
   virtual void handleMessage(cMessage *msg);
};

} //namespace

#endif
