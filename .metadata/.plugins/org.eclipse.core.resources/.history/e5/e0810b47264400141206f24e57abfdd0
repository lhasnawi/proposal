/*
 * P3DModuleDB.h
 *
 *  Created on: Sep 24, 2014
 *      Author: Luai
 */

#include <iostream>
#include <omnetpp.h>

#ifndef P3DMODULEDB_H_
#define P3DMODULEDB_H_

namespace queueing {
using namespace std;

class P3DModuleDB {
private:
    int moduleID;
    string moduleName;
    int moduleType;
    int contOutputPortID;
public:
    P3DModuleDB();
    virtual ~P3DModuleDB();
    int getModuleId() const;
    void setModuleId(int moduleId);
    const string& getModuleName() const;
    void setModuleName(const string& moduleName);
    int getModuleType() const;
    void setModuleType(int moduleType);
    int getContOutputPortID() const;
    void setContOutputPortID(int contOutputPortIndex);
};

} /* namespace queueing */

#endif /* P3DMODULEDB_H_ */
