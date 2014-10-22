//
// Generated file, do not edit! Created by opp_msgc 4.5 from SSSwitchingCont.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "SSSwitchingCont_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}



namespace queueing {

// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(SSSwitchingCont);

SSSwitchingCont::SSSwitchingCont(const char *name, int kind) : ::cMessage(name,kind)
{
    this->switchingState_var = 0;
    this->releaseTime_var = 0;
    this->StartHoldingTime_var = 0;
    this->outputPortIndex_var = 0;
    this->delay_var = 0;
    this->targetModuleID_var = 0;
    this->TargetModule_var = 0;
}

SSSwitchingCont::SSSwitchingCont(const SSSwitchingCont& other) : ::cMessage(other)
{
    copy(other);
}

SSSwitchingCont::~SSSwitchingCont()
{
}

SSSwitchingCont& SSSwitchingCont::operator=(const SSSwitchingCont& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void SSSwitchingCont::copy(const SSSwitchingCont& other)
{
    this->switchingState_var = other.switchingState_var;
    this->releaseTime_var = other.releaseTime_var;
    this->StartHoldingTime_var = other.StartHoldingTime_var;
    this->outputPortIndex_var = other.outputPortIndex_var;
    this->delay_var = other.delay_var;
    this->targetModuleID_var = other.targetModuleID_var;
    this->TargetModule_var = other.TargetModule_var;
}

void SSSwitchingCont::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->switchingState_var);
    doPacking(b,this->releaseTime_var);
    doPacking(b,this->StartHoldingTime_var);
    doPacking(b,this->outputPortIndex_var);
    doPacking(b,this->delay_var);
    doPacking(b,this->targetModuleID_var);
    doPacking(b,this->TargetModule_var);
}

void SSSwitchingCont::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->switchingState_var);
    doUnpacking(b,this->releaseTime_var);
    doUnpacking(b,this->StartHoldingTime_var);
    doUnpacking(b,this->outputPortIndex_var);
    doUnpacking(b,this->delay_var);
    doUnpacking(b,this->targetModuleID_var);
    doUnpacking(b,this->TargetModule_var);
}

bool SSSwitchingCont::getSwitchingState() const
{
    return switchingState_var;
}

void SSSwitchingCont::setSwitchingState(bool switchingState)
{
    this->switchingState_var = switchingState;
}

simtime_t SSSwitchingCont::getReleaseTime() const
{
    return releaseTime_var;
}

void SSSwitchingCont::setReleaseTime(simtime_t releaseTime)
{
    this->releaseTime_var = releaseTime;
}

simtime_t SSSwitchingCont::getStartHoldingTime() const
{
    return StartHoldingTime_var;
}

void SSSwitchingCont::setStartHoldingTime(simtime_t StartHoldingTime)
{
    this->StartHoldingTime_var = StartHoldingTime;
}

int SSSwitchingCont::getOutputPortIndex() const
{
    return outputPortIndex_var;
}

void SSSwitchingCont::setOutputPortIndex(int outputPortIndex)
{
    this->outputPortIndex_var = outputPortIndex;
}

int SSSwitchingCont::getDelay() const
{
    return delay_var;
}

void SSSwitchingCont::setDelay(int delay)
{
    this->delay_var = delay;
}

int SSSwitchingCont::getTargetModuleID() const
{
    return targetModuleID_var;
}

void SSSwitchingCont::setTargetModuleID(int targetModuleID)
{
    this->targetModuleID_var = targetModuleID;
}

const char * SSSwitchingCont::getTargetModule() const
{
    return TargetModule_var.c_str();
}

void SSSwitchingCont::setTargetModule(const char * TargetModule)
{
    this->TargetModule_var = TargetModule;
}

class SSSwitchingContDescriptor : public cClassDescriptor
{
  public:
    SSSwitchingContDescriptor();
    virtual ~SSSwitchingContDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(SSSwitchingContDescriptor);

SSSwitchingContDescriptor::SSSwitchingContDescriptor() : cClassDescriptor("queueing::SSSwitchingCont", "cMessage")
{
}

SSSwitchingContDescriptor::~SSSwitchingContDescriptor()
{
}

bool SSSwitchingContDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SSSwitchingCont *>(obj)!=NULL;
}

const char *SSSwitchingContDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SSSwitchingContDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int SSSwitchingContDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *SSSwitchingContDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "switchingState",
        "releaseTime",
        "StartHoldingTime",
        "outputPortIndex",
        "delay",
        "targetModuleID",
        "TargetModule",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int SSSwitchingContDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "switchingState")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "releaseTime")==0) return base+1;
    if (fieldName[0]=='S' && strcmp(fieldName, "StartHoldingTime")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "outputPortIndex")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "delay")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetModuleID")==0) return base+5;
    if (fieldName[0]=='T' && strcmp(fieldName, "TargetModule")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SSSwitchingContDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
        "int",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *SSSwitchingContDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int SSSwitchingContDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SSSwitchingCont *pp = (SSSwitchingCont *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SSSwitchingContDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SSSwitchingCont *pp = (SSSwitchingCont *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getSwitchingState());
        case 1: return double2string(pp->getReleaseTime());
        case 2: return double2string(pp->getStartHoldingTime());
        case 3: return long2string(pp->getOutputPortIndex());
        case 4: return long2string(pp->getDelay());
        case 5: return long2string(pp->getTargetModuleID());
        case 6: return oppstring2string(pp->getTargetModule());
        default: return "";
    }
}

bool SSSwitchingContDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SSSwitchingCont *pp = (SSSwitchingCont *)object; (void)pp;
    switch (field) {
        case 0: pp->setSwitchingState(string2bool(value)); return true;
        case 1: pp->setReleaseTime(string2double(value)); return true;
        case 2: pp->setStartHoldingTime(string2double(value)); return true;
        case 3: pp->setOutputPortIndex(string2long(value)); return true;
        case 4: pp->setDelay(string2long(value)); return true;
        case 5: pp->setTargetModuleID(string2long(value)); return true;
        case 6: pp->setTargetModule((value)); return true;
        default: return false;
    }
}

const char *SSSwitchingContDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *SSSwitchingContDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SSSwitchingCont *pp = (SSSwitchingCont *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

