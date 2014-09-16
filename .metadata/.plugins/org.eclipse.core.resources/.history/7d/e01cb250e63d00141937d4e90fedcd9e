//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __QUEUEING_OSOURCE_H
#define __QUEUEING_OSOURCE_H

#include "QueueingDefs.h"
#include "Oframe_m.h"
#include "contFrame_m.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <omnetpp.h>
#include <cmsgpar.h>
#include <list>
#include "ParameterCont_m.h"







namespace queueing {


using namespace std;

class QUEUEING_API Osource : public cSimpleModule
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

        double InterArrivalTime;
        int jobCounter;
        simsignal_t createdSignal;
        int frameCounter;
        int timeslotCounter;
        cMessage * osourceEvent;
        Oframe *frm;
        ContFrame *cont;




        simtime_t *beginingOfTheFrames;

        //string * moduleNames;
        //bool  *switchingControl;
       // bool  **path1D;
        //int **path1DGateID;
        //string **path1DModuleNames;



    protected:
        virtual Oframe *generateFrame();
        virtual ContFrame *genrateCont();

        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void finish();



    public:

        Osource();
        virtual ~Osource();

        virtual void setFrameCounter();
        virtual void setTimeslotCounter();
        void setJobCounter(int jobCounter);
        void setInterArrivalTime();
        double getInterArrivalTime();
        virtual int getFrameCounter();
        virtual int getTimeslotCounter();
        int getJobCounter() const;



        virtual void increaseFrameCounter();
        virtual void increaseTimeslotCounter();
        virtual void increaseJobCounter();
    double getDataRate();
    void setDataRate(double dataRate);

    double getGuardTime() ;
    void setGuardTime(double guardTime);

    int getNumFrames() ;
    void setNumFrames(int numFrames);

    int getNumTimeslots() ;
    void setNumTimeslots(int numTimeslots);
    double getTimeslotDuration() ;
    void setTimeslotDuration(double timeslotDuration);
    int getTimeslotSize() ;
    void setTimeslotSize(int timeslotSize);
    int getNumJobs() const;
    void setNumJobs(int numJobs);
};


}; //namespace

#endif


