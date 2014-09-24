/*
 * P3DModuleDB.cc
 *
 *  Created on: Sep 24, 2014
 *      Author: Luai
 */

#include <P3DModuleDB.h>

namespace queueing {

Define_Module(P3DModuleDB);

P3DModuleDB::P3DModuleDB() {
    // TODO Auto-generated constructor stub

}

int P3DModuleDB::getModuleId() const {
    return moduleID;
}

void P3DModuleDB::setModuleId(int moduleId) {
    moduleID = moduleId;
}

const string& P3DModuleDB::getModuleName() const {
    return moduleName;
}

void P3DModuleDB::setModuleName(const string& moduleName) {
    this->moduleName = moduleName;
}

int P3DModuleDB::getModuleType() const {
    return moduleType;
}

void P3DModuleDB::setModuleType(int moduleType) {
    this->moduleType = moduleType;
}

P3DModuleDB::~P3DModuleDB() {
    // TODO Auto-generated destructor stub
}

int P3DModuleDB::getContOutputPortID() const {
    return contOutputPortID;
}

void P3DModuleDB::setContOutputPortID(int contOutputPortID) {
    this->contOutputPortID = contOutputPortID;
}

} /* namespace queueing */


