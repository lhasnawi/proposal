//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 2006-2008 OpenSim Ltd.
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//

#ifndef __QUEUEING_QUEUE_H
#define __QUEUEING_QUEUE_H

#include "QueueingDefs.h"
#include "contFrame_m.h"
#include "Oframe_m.h"
#include "ParameterCont_m.h"
#include "Ocontroller.h"



namespace queueing {



/**
 * Abstract base class for single-server queues.
 */
class QUEUEING_API OFDL : public cSimpleModule
{
    private:
       /* simsignal_t droppedSignal;
        simsignal_t queueLengthSignal;
        simsignal_t queueingTimeSignal;
        simsignal_t busySignal;*/

        Oframe *frmServiced;
        cMessage *endServiceMsg;
        cQueue queue;
        int capacity;

        bool fifo;

        int numTimeslots;
        int timeslotSize;
        int numFrames;
        double dataRate;
        double timeslotDuration;
        double guardTime;
        double serviceTime;

        Oframe *getFromQueue();

    public:
        Ocontroller* myCtl;
        OFDL();
        virtual ~OFDL();
        int length();
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
    double getServiceTime() const;
    void setServiceTime(double serviceTime);


    protected:
        virtual void initialize();
        virtual void handleMessage(cMessage *msg);
        virtual void finish();


        // hook functions to (re)define behaviour
        virtual void arrival(Oframe *frm);
        virtual simtime_t startService(Oframe *frm);
        virtual void endService(Oframe *frm);

        virtual ContFrame *genrateCont();
        void setModuleBusyStateTo(string moduleName, bool availableState);
};

}; //namespace

#endif
