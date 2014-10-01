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

#ifndef P3DMODULEDB_H_
#define P3DMODULEDB_H_

#include <iostream>
#include <string>
#include <omnetpp.h>
#include "SSSwitchingCont_m.h"

namespace queueing {
using namespace std;

class P3DModuleDB {
private:
    int moduleID;
    string moduleName;
    int moduleType;
    int contOutputPortID;
    cQueue SwitchingContQ;
    bool busy;
    bool barState;
    int delay;
public:
    P3DModuleDB();
    virtual ~P3DModuleDB();
    int getContOutputPortId() const;
    void setContOutputPortId(int contOutputPortId);
    int getModuleId() const;
    void setModuleId(int moduleId);
    string getModuleName() const;
    void setModuleName(string moduleName);
    int getModuleType() const;
    void setModuleType(int moduleType);
    void insertInOrder(SSSwitchingCont * sw);
    bool isBarState() const;
    void setBarState(bool barState);
    bool isBusy() const;
    void setBusy(bool busy);
    int getDelay() const;
    void setDelay(int delay);
    const simtime_t& getStartHoldingTime() const;
    void setStartHoldingTime(const simtime_t& startHoldingTime);
    const cQueue& getSwitchingContQ() const;
    void setSwitchingContQ(const cQueue& switchingContQ);
    const simtime_t& getReleaseHoldingTime() const;
    void setReleaseHoldingTime(const simtime_t& releaseHoldingTime);
};

} /* namespace queueing */

#endif /* P3DMODULEDB_H_ */
