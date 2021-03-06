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

#include "Osink.h"


namespace queueing {

Define_Module(Osink);


ContFrame * Osink::genrateCont()
{
    ContFrame * cont = new ContFrame();
    return cont;

}



void Osink::initialize()
{



    /*lifeTimeSignal = registerSignal("lifeTime");
    totalQueueingTimeSignal = registerSignal("totalQueueingTime");
    queuesVisitedSignal = registerSignal("queuesVisited");
    totalServiceTimeSignal = registerSignal("totalServiceTime");
    totalDelayTimeSignal = registerSignal("totalDelayTime");
    delaysVisitedSignal = registerSignal("delaysVisited");
    generationSignal = registerSignal("generation");*/
    arrivedToSinkSignal = registerSignal("arrivedToSink");
    keepJobs = par("keepJobs");
    this->tsArrivals =0;
}

void Osink::handleMessage(cMessage *msg)
{
    if (strcmp(msg->getName(),"broadcastParameter")==0)
    {
        ParameterCont * PC = check_and_cast<ParameterCont *>(msg);
        Osink::setNumTimeslots(PC->getNumTimeslots());
        Osink::setNumFrames(PC->getNumFrames());
        Osink::setTimeslotSize(PC->getTimeslotSize());
        Osink::setDataRate(PC->getDataRate());
        Osink::setTimeslotDuration(PC->getTimeslotDuration());
        Osink::setGuardTime(PC->getGuardTime());
        delete msg;

        ContFrame *osinkCont = Osink::genrateCont();

        osinkCont->setModuleName(this->getName());
        osinkCont->setModuleID(this->getId());
        osinkCont->setModuleType(1);// module 1 -> Sink
        osinkCont->setKind(0);

        send(osinkCont,"control$o");

        //delete osinkCont;

    }
    else if (strcmp(msg->getClassName(),"queueing::Oframe")==0)
    {
    Oframe *frm = check_and_cast<Oframe *>(msg);

    //gather statistics
   /* emit(lifeTimeSignal, simTime()- job->getCreationTime());
    emit(totalQueueingTimeSignal, job->getTotalQueueingTime());
    emit(queuesVisitedSignal, job->getQueueCount());
    emit(totalServiceTimeSignal, job->getTotalServiceTime());
    emit(totalDelayTimeSignal, job->getTotalDelayTime());
    emit(delaysVisitedSignal, job->getDelayCount());
    emit(generationSignal, job->getGeneration());*/
    this->tsArrivals++;

    //cout<<"Defalut list size "<<this->defaultListSize()<<endl;
    //this->defaultListGet(tsArrivals)->removeFromOwnershipTree();
    //this->dropAndDelete(msg);
    frm->removeFromOwnershipTree();

    //cout<<"Defalut list contains "<<this->defaultListContains(frm)<<endl;





  /* if (!keepJobs)
        {
        delete  msg;

        }*/
    }
    else if (strcmp(msg->getName(),"Broadcast")==0)
    {
        P3DBroadcastParameter * BP = check_and_cast<P3DBroadcastParameter *>(msg);
        this->numTimeslots = BP->getNumberOfTimeslots();
        this->numFrames = BP->getNumberOfFrames();
        this->numberOfJobs = numTimeslots * numFrames;
        delete msg;


    }

}




Osink::Osink() {
    tsArrivals=0;
}

Osink::~Osink() {
    //int dListSize = this->defaultListSize();
    //Oframe *frm;



    //this->drop()
    /*for (int i = 0 ; i<dListSize-1; i++)
    {

                cOwnedObject *obj =this->defaultListGet(i);
        obj->removeFromOwnershipTree();
    }*/


}

void Osink::finish()
{

    emit(arrivedToSinkSignal, tsArrivals);
}

double Osink::getDataRate() const {
    return dataRate;
}

void Osink::setDataRate(double dataRate) {
    this->dataRate = dataRate;
}

double Osink::getGuardTime() const {
    return guardTime;
}

void Osink::setGuardTime(double guardTime) {
    this->guardTime = guardTime;
}

int Osink::getNumFrames() const {
    return numFrames;
}

void Osink::setNumFrames(int numFrames) {
    this->numFrames = numFrames;
}

int Osink::getNumTimeslots() const {
    return numTimeslots;
}

void Osink::setNumTimeslots(int numTimeslots) {
    this->numTimeslots = numTimeslots;
}

double Osink::getTimeslotDuration() const {
    return timeslotDuration;
}

void Osink::setTimeslotDuration(double timeslotDuration) {
    this->timeslotDuration = timeslotDuration;
}

int Osink::getTimeslotSize() const {
    return timeslotSize;
}

void Osink::setTimeslotSize(int timeslotSize) {
    this->timeslotSize = timeslotSize;
}



} //namespace
