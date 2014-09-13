

#ifndef OCOMBINER_H_
#define OCOMBINER_H_

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

class Ocombiner : public cSimpleModule {

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
   bool moduleUsed;
   int droppedTS;
   ContFrame *cont;



public:
  // list <SwitchingCont> SwitchingContQ;

   Ocombiner();
   Ocontroller* myCtl;
   virtual ~Ocombiner();
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
    simtime_t getTimeslotDuration();
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
   void sortedInsert(SwitchingCont* new_node);

};

} /* namespace queueing */
#endif /* OSWITCH_H_ */
