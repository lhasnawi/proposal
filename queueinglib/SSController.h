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

#ifndef __QUEUEINGLIB_SSCONTROLLER_H_
#define __QUEUEINGLIB_SSCONTROLLER_H_

#include <omnetpp.h>
#include <list>
#include <string>
#include <iostream>
#include <P3DModuleDB.h>
#include "P3DModuleCont_m.h"
#include "P3DBroadcastParameter_m.h"
#include <fstream>


namespace queueing {

/**
 * TODO - Generated class
 */
class SSController : public cSimpleModule
{
    private:
        int numberOfTimeslots;
        int numberOfFrames;
        int timeslotCounter;
        int frameCounter;
        int timeslotSize;
        double dataRate;
        double timeslotDuration;
        double guardTime;
        cMessage * P3DControllerEvent;
        P3DBroadcastParameter * BC;
        list <P3DModuleDB> sourceSinkList;
        list <P3DModuleDB> switchesList;
        string **pathNames;
        int **commulatedDelayMatrix;
        int evenTimeslotAssignment;
        int oddTimeslotAssignment;

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    virtual void broadcastParameter();
    int getOutputTimeslot(int row, int column);
    int computeDelay(int in, int out);
    void reservePath(int pathIndex, int delay);
    void setDelayMatrix();
};

} //namespace

#endif
