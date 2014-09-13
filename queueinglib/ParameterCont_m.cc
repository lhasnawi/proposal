//
// Generated file, do not edit! Created by opp_msgc 4.5 from ParameterCont.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "ParameterCont_m.h"

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

Register_Class(ParameterCont);

ParameterCont::ParameterCont(const char *name, int kind) : ::cMessage(name,kind)
{
    this->frameType_var = 1;
    this->numTimeslots_var = 0;
    this->numFrames_var = 0;
    this->timeslotSize_var = 0;
    this->dataRate_var = 0;
    this->timeslotDuration_var = 0;
    this->guardTime_var = 0;
}

ParameterCont::ParameterCont(const ParameterCont& other) : ::cMessage(other)
{
    copy(other);
}

ParameterCont::~ParameterCont()
{
}

ParameterCont& ParameterCont::operator=(const ParameterCont& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ParameterCont::copy(const ParameterCont& other)
{
    this->frameType_var = other.frameType_var;
    this->numTimeslots_var = other.numTimeslots_var;
    this->numFrames_var = other.numFrames_var;
    this->timeslotSize_var = other.timeslotSize_var;
    this->dataRate_var = other.dataRate_var;
    this->timeslotDuration_var = other.timeslotDuration_var;
    this->guardTime_var = other.guardTime_var;
}

void ParameterCont::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->frameType_var);
    doPacking(b,this->numTimeslots_var);
    doPacking(b,this->numFrames_var);
    doPacking(b,this->timeslotSize_var);
    doPacking(b,this->dataRate_var);
    doPacking(b,this->timeslotDuration_var);
    doPacking(b,this->guardTime_var);
}

void ParameterCont::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->numTimeslots_var);
    doUnpacking(b,this->numFrames_var);
    doUnpacking(b,this->timeslotSize_var);
    doUnpacking(b,this->dataRate_var);
    doUnpacking(b,this->timeslotDuration_var);
    doUnpacking(b,this->guardTime_var);
}

int ParameterCont::getFrameType() const
{
    return frameType_var;
}

void ParameterCont::setFrameType(int frameType)
{
    this->frameType_var = frameType;
}

int ParameterCont::getNumTimeslots() const
{
    return numTimeslots_var;
}

void ParameterCont::setNumTimeslots(int numTimeslots)
{
    this->numTimeslots_var = numTimeslots;
}

int ParameterCont::getNumFrames() const
{
    return numFrames_var;
}

void ParameterCont::setNumFrames(int numFrames)
{
    this->numFrames_var = numFrames;
}

int ParameterCont::getTimeslotSize() const
{
    return timeslotSize_var;
}

void ParameterCont::setTimeslotSize(int timeslotSize)
{
    this->timeslotSize_var = timeslotSize;
}

double ParameterCont::getDataRate() const
{
    return dataRate_var;
}

void ParameterCont::setDataRate(double dataRate)
{
    this->dataRate_var = dataRate;
}

double ParameterCont::getTimeslotDuration() const
{
    return timeslotDuration_var;
}

void ParameterCont::setTimeslotDuration(double timeslotDuration)
{
    this->timeslotDuration_var = timeslotDuration;
}

double ParameterCont::getGuardTime() const
{
    return guardTime_var;
}

void ParameterCont::setGuardTime(double guardTime)
{
    this->guardTime_var = guardTime;
}

class ParameterContDescriptor : public cClassDescriptor
{
  public:
    ParameterContDescriptor();
    virtual ~ParameterContDescriptor();

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

Register_ClassDescriptor(ParameterContDescriptor);

ParameterContDescriptor::ParameterContDescriptor() : cClassDescriptor("queueing::ParameterCont", "cMessage")
{
}

ParameterContDescriptor::~ParameterContDescriptor()
{
}

bool ParameterContDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ParameterCont *>(obj)!=NULL;
}

const char *ParameterContDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ParameterContDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount(object) : 7;
}

unsigned int ParameterContDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *ParameterContDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "frameType",
        "numTimeslots",
        "numFrames",
        "timeslotSize",
        "dataRate",
        "timeslotDuration",
        "guardTime",
    };
    return (field>=0 && field<7) ? fieldNames[field] : NULL;
}

int ParameterContDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameType")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numTimeslots")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numFrames")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeslotSize")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataRate")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeslotDuration")==0) return base+5;
    if (fieldName[0]=='g' && strcmp(fieldName, "guardTime")==0) return base+6;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ParameterContDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
        "int",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : NULL;
}

const char *ParameterContDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ParameterContDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ParameterCont *pp = (ParameterCont *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ParameterContDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ParameterCont *pp = (ParameterCont *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFrameType());
        case 1: return long2string(pp->getNumTimeslots());
        case 2: return long2string(pp->getNumFrames());
        case 3: return long2string(pp->getTimeslotSize());
        case 4: return double2string(pp->getDataRate());
        case 5: return double2string(pp->getTimeslotDuration());
        case 6: return double2string(pp->getGuardTime());
        default: return "";
    }
}

bool ParameterContDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ParameterCont *pp = (ParameterCont *)object; (void)pp;
    switch (field) {
        case 0: pp->setFrameType(string2long(value)); return true;
        case 1: pp->setNumTimeslots(string2long(value)); return true;
        case 2: pp->setNumFrames(string2long(value)); return true;
        case 3: pp->setTimeslotSize(string2long(value)); return true;
        case 4: pp->setDataRate(string2double(value)); return true;
        case 5: pp->setTimeslotDuration(string2double(value)); return true;
        case 6: pp->setGuardTime(string2double(value)); return true;
        default: return false;
    }
}

const char *ParameterContDescriptor::getFieldStructName(void *object, int field) const
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

void *ParameterContDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ParameterCont *pp = (ParameterCont *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

