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

#ifndef __QUEUEINGLIB_SOURCE3D_H_
#define __QUEUEINGLIB_SOURCE3D_H_


#include "QueueingDefs.h"
#include "Oframe_m.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <omnetpp.h>
#include <cmsgpar.h>
#include <list>
#include "ParameterCont_m.h"

namespace queueing {

using namespace std;


class Source3D : public cSimpleModule
{
private:
    simtime_t startTime;
    simtime_t stopTime;
    simsignal_t timeslotSignal;
    int numJobs;

    int numTimeslots;
    int timeslotSize;
    int numFrames;
    double dataRate;
    double timeslotDuration;
    double guardTime;
    int wavelength;

    double InterArrivalTime;
    int jobCounter;
    simsignal_t createdSignal;
    int frameCounter;
    int timeslotCounter;
    cMessage * osourceEvent;
    Oframe *frm;

    simtime_t *beginingOfTheFrames;

protected:
    virtual Oframe *generateFrame();
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void finish();



public:

    Source3D();
    virtual ~Source3D();

    void setInterArrivalTime();
    double getInterArrivalTime();

    virtual void setFrameCounter();
    virtual int getFrameCounter();
    virtual void increaseFrameCounter();

    virtual void setTimeslotCounter();
    virtual void increaseTimeslotCounter();
    virtual int getTimeslotCounter();

    virtual void increaseJobCounter();
    int getJobCounter() const;
    void setJobCounter(int jobCounter);

    double getDataRate();
    void setDataRate(double dataRate);

    double getGuardTime() ;
    void setGuardTime();

    int getNumFrames() ;
    void setNumFrames(int numFrames);

    int getNumTimeslots() ;
    void setNumTimeslots(int numTimeslots);

    double getTimeslotDuration() ;
    void setTimeslotDuration();

    int getTimeslotSize() ;
    void setTimeslotSize(int timeslotSize);

    int getNumJobs() const;
    void setNumJobs(int numJobs);
};



}; //namespace

#endif