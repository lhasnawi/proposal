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

#ifndef __QUEUEINGLIB_OSINK_H_
#define __QUEUEINGLIB_OSINK_H_

#include "QueueingDefs.h"
#include "contFrame_m.h"
#include "Oframe_m.h"
#include "ParameterCont_m.h"
#include <cmessage.h>
using namespace std;


namespace queueing {

/**
 * TODO - Generated class
 */
class Osink : public cSimpleModule
{
public:
    Osink();
    virtual ~Osink();
    double getDataRate() const;
    void setDataRate(double dataRate);
    double getGuardTime() const;
    void setGuardTime(double guardTime);
    int getNumFrames() const;
    void setNumFrames(int numFrames);
    int getNumTimeslots() const;
    void setNumTimeslots(int numTimeslots);
    double getTimeslotDuration() const;
    void setTimeslotDuration(double timeslotDuration);
    int getTimeslotSize() const;
    void setTimeslotSize(int timeslotSize);

private:
  /*simsignal_t lifeTimeSignal;
  simsignal_t totalQueueingTimeSignal;
  simsignal_t queuesVisitedSignal;
  simsignal_t totalServiceTimeSignal;
  simsignal_t totalDelayTimeSignal;
  simsignal_t delaysVisitedSignal;
  simsignal_t generationSignal;*/
  simsignal_t arrivedToSinkSignal;
  bool keepJobs;

  int numTimeslots;
  int timeslotSize;
  int numFrames;
  int tsArrivals;
  double dataRate;
  double timeslotDuration;
  double guardTime;
 // cMessage * osinkEvent;


protected:
  virtual ContFrame *genrateCont();
  virtual void initialize();
  virtual void handleMessage(cMessage *msg);
  virtual void finish();


};

} //namespace

#endif
