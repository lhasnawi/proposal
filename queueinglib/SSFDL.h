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

#ifndef __QUEUEINGLIB_SSFDL_H_
#define __QUEUEINGLIB_SSFDL_H_

#include <omnetpp.h>
#include "QueueingDefs.h"
#include "Oframe_m.h"
#include "P3DBroadcastParameter_m.h"

namespace queueing {

/**
 * TODO - Generated class
 */
class SSFDL : public cSimpleModule
{
private:
       Oframe *frmServiced;
       cMessage *endServiceMsg;
       cQueue queue;
       int capacity;

       bool fifo;

       double timeslotDuration;
       double guardTime;
       double serviceTime;
       int numberOfTimeslots;
       int numberOfFrames;

       Oframe *getFromQueue();

  protected:
       ~SSFDL();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void arrival(Oframe *frm);
    virtual simtime_t startService(Oframe *frm);
    virtual void endService(Oframe *frm);
    double getServiceTime();
    void setServiceTime(double serviceTime);
};

} //namespace

#endif
