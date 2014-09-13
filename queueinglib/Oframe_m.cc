//
// Generated file, do not edit! Created by opp_msgc 4.5 from Oframe.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "Oframe_m.h"

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

Register_Class(Oframe);

Oframe::Oframe(const char *name, int kind) : ::cPacket(name,kind)
{
    this->frameIndex_var = 0;
    this->timeslotIndex_var = 0;
    this->frameDelayed_var = 0;
    this->newFrameIndex_var = 0;
    this->newTimeslotIndex_var = 0;
    this->totalDelayTime_var = 0;
    this->delayCount_var = 0;
}

Oframe::Oframe(const Oframe& other) : ::cPacket(other)
{
    copy(other);
}

Oframe::~Oframe()
{
}

Oframe& Oframe::operator=(const Oframe& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Oframe::copy(const Oframe& other)
{
    this->frameIndex_var = other.frameIndex_var;
    this->timeslotIndex_var = other.timeslotIndex_var;
    this->frameDelayed_var = other.frameDelayed_var;
    this->newFrameIndex_var = other.newFrameIndex_var;
    this->newTimeslotIndex_var = other.newTimeslotIndex_var;
    this->totalDelayTime_var = other.totalDelayTime_var;
    this->delayCount_var = other.delayCount_var;
}

void Oframe::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->frameIndex_var);
    doPacking(b,this->timeslotIndex_var);
    doPacking(b,this->frameDelayed_var);
    doPacking(b,this->newFrameIndex_var);
    doPacking(b,this->newTimeslotIndex_var);
    doPacking(b,this->totalDelayTime_var);
    doPacking(b,this->delayCount_var);
}

void Oframe::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->frameIndex_var);
    doUnpacking(b,this->timeslotIndex_var);
    doUnpacking(b,this->frameDelayed_var);
    doUnpacking(b,this->newFrameIndex_var);
    doUnpacking(b,this->newTimeslotIndex_var);
    doUnpacking(b,this->totalDelayTime_var);
    doUnpacking(b,this->delayCount_var);
}

int Oframe::getFrameIndex() const
{
    return frameIndex_var;
}

void Oframe::setFrameIndex(int frameIndex)
{
    this->frameIndex_var = frameIndex;
}

int Oframe::getTimeslotIndex() const
{
    return timeslotIndex_var;
}

void Oframe::setTimeslotIndex(int timeslotIndex)
{
    this->timeslotIndex_var = timeslotIndex;
}

bool Oframe::getFrameDelayed() const
{
    return frameDelayed_var;
}

void Oframe::setFrameDelayed(bool frameDelayed)
{
    this->frameDelayed_var = frameDelayed;
}

int Oframe::getNewFrameIndex() const
{
    return newFrameIndex_var;
}

void Oframe::setNewFrameIndex(int newFrameIndex)
{
    this->newFrameIndex_var = newFrameIndex;
}

int Oframe::getNewTimeslotIndex() const
{
    return newTimeslotIndex_var;
}

void Oframe::setNewTimeslotIndex(int newTimeslotIndex)
{
    this->newTimeslotIndex_var = newTimeslotIndex;
}

simtime_t Oframe::getTotalDelayTime() const
{
    return totalDelayTime_var;
}

void Oframe::setTotalDelayTime(simtime_t totalDelayTime)
{
    this->totalDelayTime_var = totalDelayTime;
}

int Oframe::getDelayCount() const
{
    return delayCount_var;
}

void Oframe::setDelayCount(int delayCount)
{
    this->delayCount_var = delayCount;
}

class OframeDescriptor : public cClassDescriptor
{
  public:
    OframeDescriptor();
    virtual ~OframeDescriptor();

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

Register_ClassDescriptor(OframeDescriptor);

OframeDescriptor::OframeDescriptor() : cClassDescriptor("queueing::Oframe", "cPacket")
{
}

OframeDescriptor::~OframeDescriptor()
{
}

bool OframeDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<Oframe *>(obj)!=NULL;
}

const char *OframeDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int OframeDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int OframeDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *OframeDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "frameIndex",
        "timeslotIndex",
        "frameDelayed",
        "newFrameIndex",
        "newTimeslotIndex",
        "totalDelayTime",
        "delayCount",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int OframeDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameIndex")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeslotIndex")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameDelayed")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "newFrameIndex")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "newTimeslotIndex")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalDelayTime")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayCount")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *OframeDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "bool",
        "int",
        "int",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *OframeDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int OframeDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    Oframe *pp = (Oframe *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string OframeDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    Oframe *pp = (Oframe *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFrameIndex());
        case 1: return long2string(pp->getTimeslotIndex());
        case 2: return bool2string(pp->getFrameDelayed());
        case 3: return long2string(pp->getNewFrameIndex());
        case 4: return long2string(pp->getNewTimeslotIndex());
        case 5: return double2string(pp->getTotalDelayTime());
        case 6: return long2string(pp->getDelayCount());
        default: return "";
    }
}

bool OframeDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    Oframe *pp = (Oframe *)object; (void)pp;
    switch (field) {
        case 0: pp->setFrameIndex(string2long(value)); return true;
        case 1: pp->setTimeslotIndex(string2long(value)); return true;
        case 2: pp->setFrameDelayed(string2bool(value)); return true;
        case 3: pp->setNewFrameIndex(string2long(value)); return true;
        case 4: pp->setNewTimeslotIndex(string2long(value)); return true;
        case 5: pp->setTotalDelayTime(string2double(value)); return true;
        case 6: pp->setDelayCount(string2long(value)); return true;
        default: return false;
    }
}

const char *OframeDescriptor::getFieldStructName(void *object, int field) const
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

void *OframeDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    Oframe *pp = (Oframe *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

