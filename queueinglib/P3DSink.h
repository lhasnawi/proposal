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

#ifndef __QUEUEINGLIB_P3DSINK_H_
#define __QUEUEINGLIB_P3DSINK_H_

#include <omnetpp.h>
#include "P3DTimeslot_m.h"
#include "P3DModuleCont_m.h"
#include "P3DBroadcastParameter_m.h"

namespace queueing {

/**
 * TODO - Generated class
 */
class P3DSink : public cSimpleModule
{
private:
    int arrivals;
    int numberOfTimeslots;
    int numberOfFrames;
protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);
    P3DModuleCont * genrateModuleCont();
};

} //namespace

#endif
