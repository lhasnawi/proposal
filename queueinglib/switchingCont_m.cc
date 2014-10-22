//
// Generated file, do not edit! Created by opp_msgc 4.5 from switchingCont.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "switchingCont_m.h"

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

Register_Class(SwitchingCont);

SwitchingCont::SwitchingCont(const char *name, int kind) : ::cPacket(name,kind)
{
    this->frameType_var = 2;
    this->switchingState_var = 0;
    this->releaseTime_var = 0;
    this->StartHoldingTime_var = 0;
    this->outputPortIndex_var = 0;
    this->delay_var = 0;
    this->targetModule_var = 0;
}

SwitchingCont::SwitchingCont(const SwitchingCont& other) : ::cPacket(other)
{
    copy(other);
}

SwitchingCont::~SwitchingCont()
{
}

SwitchingCont& SwitchingCont::operator=(const SwitchingCont& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SwitchingCont::copy(const SwitchingCont& other)
{
    this->frameType_var = other.frameType_var;
    this->switchingState_var = other.switchingState_var;
    this->releaseTime_var = other.releaseTime_var;
    this->StartHoldingTime_var = other.StartHoldingTime_var;
    this->outputPortIndex_var = other.outputPortIndex_var;
    this->delay_var = other.delay_var;
    this->targetModule_var = other.targetModule_var;
}

void SwitchingCont::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->frameType_var);
    doPacking(b,this->switchingState_var);
    doPacking(b,this->releaseTime_var);
    doPacking(b,this->StartHoldingTime_var);
    doPacking(b,this->outputPortIndex_var);
    doPacking(b,this->delay_var);
    doPacking(b,this->targetModule_var);
}

void SwitchingCont::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->switchingState_var);
    doUnpacking(b,this->releaseTime_var);
    doUnpacking(b,this->StartHoldingTime_var);
    doUnpacking(b,this->outputPortIndex_var);
    doUnpacking(b,this->delay_var);
    doUnpacking(b,this->targetModule_var);
}

int SwitchingCont::getFrameType() const
{
    return frameType_var;
}

void SwitchingCont::setFrameType(int frameType)
{
    this->frameType_var = frameType;
}

bool SwitchingCont::getSwitchingState() const
{
    return switchingState_var;
}

void SwitchingCont::setSwitchingState(bool switchingState)
{
    this->switchingState_var = switchingState;
}

simtime_t SwitchingCont::getReleaseTime() const
{
    return releaseTime_var;
}

void SwitchingCont::setReleaseTime(simtime_t releaseTime)
{
    this->releaseTime_var = releaseTime;
}

simtime_t SwitchingCont::getStartHoldingTime() const
{
    return StartHoldingTime_var;
}

void SwitchingCont::setStartHoldingTime(simtime_t StartHoldingTime)
{
    this->StartHoldingTime_var = StartHoldingTime;
}

int SwitchingCont::getOutputPortIndex() const
{
    return outputPortIndex_var;
}

void SwitchingCont::setOutputPortIndex(int outputPortIndex)
{
    this->outputPortIndex_var = outputPortIndex;
}

int SwitchingCont::getDelay() const
{
    return delay_var;
}

void SwitchingCont::setDelay(int delay)
{
    this->delay_var = delay;
}

const char * SwitchingCont::getTargetModule() const
{
    return targetModule_var.c_str();
}

void SwitchingCont::setTargetModule(const char * targetModule)
{
    this->targetModule_var = targetModule;
}

class SwitchingContDescriptor : public cClassDescriptor
{
  public:
    SwitchingContDescriptor();
    virtual ~SwitchingContDescriptor();

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

Register_ClassDescriptor(SwitchingContDescriptor);

SwitchingContDescriptor::SwitchingContDescriptor() : cClassDescriptor("queueing::SwitchingCont", "cPacket")
{
}

SwitchingContDescriptor::~SwitchingContDescriptor()
{
}

bool SwitchingContDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<SwitchingCont *>(obj)!=NULL;
}

const char *SwitchingContDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int SwitchingContDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int SwitchingContDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *SwitchingContDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "frameType",
        "switchingState",
        "releaseTime",
        "StartHoldingTime",
        "outputPortIndex",
        "delay",
        "targetModule",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int SwitchingContDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameType")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "switchingState")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "releaseTime")==0) return base+2;
    if (fieldName[0]=='S' && strcmp(fieldName, "StartHoldingTime")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "outputPortIndex")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "delay")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetModule")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *SwitchingContDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *SwitchingContDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int SwitchingContDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    SwitchingCont *pp = (SwitchingCont *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string SwitchingContDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    SwitchingCont *pp = (SwitchingCont *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFrameType());
        case 1: return bool2string(pp->getSwitchingState());
        case 2: return double2string(pp->getReleaseTime());
        case 3: return double2string(pp->getStartHoldingTime());
        case 4: return long2string(pp->getOutputPortIndex());
        case 5: return long2string(pp->getDelay());
        case 6: return oppstring2string(pp->getTargetModule());
        default: return "";
    }
}

bool SwitchingContDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    SwitchingCont *pp = (SwitchingCont *)object; (void)pp;
    switch (field) {
        case 0: pp->setFrameType(string2long(value)); return true;
        case 1: pp->setSwitchingState(string2bool(value)); return true;
        case 2: pp->setReleaseTime(string2double(value)); return true;
        case 3: pp->setStartHoldingTime(string2double(value)); return true;
        case 4: pp->setOutputPortIndex(string2long(value)); return true;
        case 5: pp->setDelay(string2long(value)); return true;
        case 6: pp->setTargetModule((value)); return true;
        default: return false;
    }
}

const char *SwitchingContDescriptor::getFieldStructName(void *object, int field) const
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

void *SwitchingContDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    SwitchingCont *pp = (SwitchingCont *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

