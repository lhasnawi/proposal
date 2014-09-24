//
// Generated file, do not edit! Created by opp_msgc 4.5 from P3DTimeslot.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "P3DTimeslot_m.h"

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

Register_Class(P3DTimeslot);

P3DTimeslot::P3DTimeslot(const char *name, int kind) : ::cPacket(name,kind)
{
    this->timeslotIndex_var = 0;
    this->frameIndex_var = 0;
}

P3DTimeslot::P3DTimeslot(const P3DTimeslot& other) : ::cPacket(other)
{
    copy(other);
}

P3DTimeslot::~P3DTimeslot()
{
}

P3DTimeslot& P3DTimeslot::operator=(const P3DTimeslot& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void P3DTimeslot::copy(const P3DTimeslot& other)
{
    this->timeslotIndex_var = other.timeslotIndex_var;
    this->frameIndex_var = other.frameIndex_var;
}

void P3DTimeslot::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->timeslotIndex_var);
    doPacking(b,this->frameIndex_var);
}

void P3DTimeslot::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->timeslotIndex_var);
    doUnpacking(b,this->frameIndex_var);
}

int P3DTimeslot::getTimeslotIndex() const
{
    return timeslotIndex_var;
}

void P3DTimeslot::setTimeslotIndex(int timeslotIndex)
{
    this->timeslotIndex_var = timeslotIndex;
}

int P3DTimeslot::getFrameIndex() const
{
    return frameIndex_var;
}

void P3DTimeslot::setFrameIndex(int frameIndex)
{
    this->frameIndex_var = frameIndex;
}

class P3DTimeslotDescriptor : public cClassDescriptor
{
  public:
    P3DTimeslotDescriptor();
    virtual ~P3DTimeslotDescriptor();

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

Register_ClassDescriptor(P3DTimeslotDescriptor);

P3DTimeslotDescriptor::P3DTimeslotDescriptor() : cClassDescriptor("queueing::P3DTimeslot", "cPacket")
{
}

P3DTimeslotDescriptor::~P3DTimeslotDescriptor()
{
}

bool P3DTimeslotDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<P3DTimeslot *>(obj)!=NULL;
}

const char *P3DTimeslotDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int P3DTimeslotDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int P3DTimeslotDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *P3DTimeslotDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "timeslotIndex",
        "frameIndex",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int P3DTimeslotDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeslotIndex")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameIndex")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *P3DTimeslotDescriptor::getFieldTypeString(void *object, int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : NULL;
}

const char *P3DTimeslotDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int P3DTimeslotDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    P3DTimeslot *pp = (P3DTimeslot *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string P3DTimeslotDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    P3DTimeslot *pp = (P3DTimeslot *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTimeslotIndex());
        case 1: return long2string(pp->getFrameIndex());
        default: return "";
    }
}

bool P3DTimeslotDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    P3DTimeslot *pp = (P3DTimeslot *)object; (void)pp;
    switch (field) {
        case 0: pp->setTimeslotIndex(string2long(value)); return true;
        case 1: pp->setFrameIndex(string2long(value)); return true;
        default: return false;
    }
}

const char *P3DTimeslotDescriptor::getFieldStructName(void *object, int field) const
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

void *P3DTimeslotDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    P3DTimeslot *pp = (P3DTimeslot *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

