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

#include "Source3D.h"

namespace queueing {

Define_Module(Source3D);

void *srcPtr3D = NULL;



Define_Module(Source3D);

Oframe * Source3D::generateFrame()
{

    if (Source3D::getTimeslotCounter()==0 && Source3D::getFrameCounter()==0)
    {
        // Create Oframe object
                    //Oframe *
                    frm = new Oframe();
                    frm->setFrameIndex(Source3D::getFrameCounter());
                    frm->setTimeslotIndex(Source3D::getTimeslotCounter());
                    frm->setByteLength(this->getTimeslotSize());
                    frm->setFrameDelayed(false);
                    frm->setDelayCount(0);
                    Source3D::increaseTimeslotCounter();
                    frm->setKind(4);
                    return frm;

    }
    else if (timeslotCounter>=Source3D::getNumTimeslots())
        {

            Source3D::setTimeslotCounter();
            //Source3D::increaseFrameCounter();

            // Create Oframe object
            //Oframe *
            frm = new Oframe();
            frm->setFrameIndex(Source3D::getFrameCounter());
            frm->setTimeslotIndex(Source3D::getTimeslotCounter());
            frm->setByteLength(this->getTimeslotSize());
            frm->setFrameDelayed(false);
            frm->setDelayCount(0);
            Source3D::increaseTimeslotCounter();
            frm->setKind(4);
            return frm;

        }
    else
        {


            // Create Oframe object
            //Oframe *
            frm = new Oframe();
            frm->setFrameIndex(Source3D::getFrameCounter());
            frm->setTimeslotIndex(Source3D::getTimeslotCounter());
            frm->setByteLength(this->getTimeslotSize());
            frm->setFrameDelayed(false);
            frm->setNewTimeslotIndex(Source3D::getTimeslotCounter());
            frm->setNewFrameIndex(Source3D::getFrameCounter());
            frm->setDelayCount(0);
            Source3D::increaseTimeslotCounter();
            frm->setKind(4);
            return frm;


        }

}



Source3D::Source3D()
{
    Source3D::setTimeslotCounter();
    Source3D::setFrameCounter();
    srcPtr3D = this;

}

Source3D::~Source3D()
{
    cancelAndDelete(osourceEvent);
    delete frm;



}

void Source3D::initialize()
{

    createdSignal = registerSignal("created");
    jobCounter = 0;
    WATCH(jobCounter);
    WATCH(InterArrivalTime);
    WATCH(timeslotSize);
    WATCH(timeslotDuration);
    WATCH(guardTime);
    this->frameCounter = 0;
    this->timeslotCounter = 0;

    startTime = par("startTime");
    stopTime = par("stopTime");
    numJobs = par("numJobs");

    //Schedule the First Message for sync
    osourceEvent = new cMessage();
    osourceEvent->setName("osourceEvent");
    osourceEvent->setKind(3);

    //get input from NED file
    this->numTimeslots = par("numTimeslotsP");
    this->timeslotSize = par("timeslotSizeP");
    this->numFrames = par ("numFramesP");
    this->dataRate = par ("dataRateP");
    this->wavelength = par("wavelengthP");
    this->setTimeslotDuration();
    this->setGuardTime();
    Source3D::setInterArrivalTime();
    scheduleAt(0, osourceEvent);


}

void Source3D::handleMessage(cMessage *msg)
{

     if (strcmp(msg->getName(),"osourceEvent")==0) //&& (stopTime < 0 || stopTime > simTime()))
    {
        if (numJobs < 0 || numJobs > jobCounter)
        {

          // reschedule the timer for the next message
          scheduleAt(simTime()+Source3D::getTimeslotDuration(), osourceEvent);

          Oframe *frm = generateFrame();
          Source3D::increaseJobCounter();


          send(frm, "out");
        }
        else
        {
            Source3D::finish();
        }


    }
    else
    {
        // finished
    }// end else
}//end handle

void Source3D::finish()
{
    emit(createdSignal, jobCounter);

}

        //Setters

void Source3D::setFrameCounter()
{
    frameCounter = 0;
}

void Source3D::setTimeslotCounter()
{
    timeslotCounter =0;
}



double Source3D::getInterArrivalTime()
{
    return InterArrivalTime;
}

void Source3D::setInterArrivalTime()
{
    InterArrivalTime = Source3D::getTimeslotDuration()+Source3D::getGuardTime();
}

void Source3D::setJobCounter(int jobCounter)
{
    this->jobCounter = jobCounter;
}



        //Getters



int Source3D::getFrameCounter()
{
    return frameCounter;
}

int Source3D::getTimeslotCounter()
{
    return timeslotCounter;
}

int Source3D::getJobCounter() const
{
    return jobCounter;
}



void Source3D::increaseFrameCounter()
{
    if (Source3D::getFrameCounter()<Source3D::getNumFrames()-1)
     this->frameCounter++;
    else
        Source3D::setFrameCounter();
}

void Source3D::increaseTimeslotCounter()
{

    if (Source3D::getTimeslotCounter()<Source3D::getNumTimeslots()-1)
        this->timeslotCounter++;
    else
    {
        Source3D::setTimeslotCounter();
        Source3D::increaseFrameCounter();
    }

}

double Source3D::getDataRate()  {
    return dataRate;
}

void Source3D::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Source3D::getGuardTime()  {
    return guardTime;
}

void Source3D::setGuardTime() {
    this->guardTime = this->getTimeslotDuration()*.1;

}

int Source3D::getNumFrames()  {
    return numFrames;
}

void Source3D::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Source3D::getNumTimeslots()  {
    return numTimeslots;
}

void Source3D::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

double Source3D::getTimeslotDuration()  {
    return timeslotDuration;
}

void Source3D::setTimeslotDuration() {
    this->timeslotDuration = this->getTimeslotSize()/this->getDataRate();
}

int Source3D::getTimeslotSize()  {
    return timeslotSize;
}

int Source3D::getNumJobs() const {
    return numJobs;
}

void Source3D::setNumJobs(int numJobs) {
    this->numJobs = numJobs;
}

void Source3D::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}

void Source3D::increaseJobCounter()
{

    this->jobCounter++;
}





} //namespace
