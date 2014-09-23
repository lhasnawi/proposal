//
// Generated file, do not edit! Created by opp_msgc 4.5 from P3DBroadcastParameter.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "P3DBroadcastParameter_m.h"

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

Register_Class(P3DBroadcastParameter);

P3DBroadcastParameter::P3DBroadcastParameter(const char *name, int kind) : ::cMessage(name,kind)
{
    this->numberOfTimeslots_var = 0;
    this->numberOfFrames_var = 0;
}

P3DBroadcastParameter::P3DBroadcastParameter(const P3DBroadcastParameter& other) : ::cMessage(other)
{
    copy(other);
}

P3DBroadcastParameter::~P3DBroadcastParameter()
{
}

P3DBroadcastParameter& P3DBroadcastParameter::operator=(const P3DBroadcastParameter& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void P3DBroadcastParameter::copy(const P3DBroadcastParameter& other)
{
    this->numberOfTimeslots_var = other.numberOfTimeslots_var;
    this->numberOfFrames_var = other.numberOfFrames_var;
}

void P3DBroadcastParameter::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->numberOfTimeslots_var);
    doPacking(b,this->numberOfFrames_var);
}

void P3DBroadcastParameter::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->numberOfTimeslots_var);
    doUnpacking(b,this->numberOfFrames_var);
}

int P3DBroadcastParameter::getNumberOfTimeslots() const
{
    return numberOfTimeslots_var;
}

void P3DBroadcastParameter::setNumberOfTimeslots(int numberOfTimeslots)
{
    this->numberOfTimeslots_var = numberOfTimeslots;
}

int P3DBroadcastParameter::getNumberOfFrames() const
{
    return numberOfFrames_var;
}

void P3DBroadcastParameter::setNumberOfFrames(int numberOfFrames)
{
    this->numberOfFrames_var = numberOfFrames;
}

class P3DBroadcastParameterDescriptor : public cClassDescriptor
{
  public:
    P3DBroadcastParameterDescriptor();
    virtual ~P3DBroadcastParameterDescriptor();

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

Register_ClassDescriptor(P3DBroadcastParameterDescriptor);

P3DBroadcastParameterDescriptor::P3DBroadcastParameterDescriptor() : cClassDescriptor("queueing::P3DBroadcastParameter", "cMessage")
{
}

P3DBroadcastParameterDescriptor::~P3DBroadcastParameterDescriptor()
{
}

bool P3DBroadcastParameterDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<P3DBroadcastParameter *>(obj)!=NULL;
}

const char *P3DBroadcastParameterDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int P3DBroadcastParameterDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount(object) : 2;
}

unsigned int P3DBroadcastParameterDescriptor::getFieldTypeFlags(void *object, int field) const
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

const char *P3DBroadcastParameterDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "numberOfTimeslots",
        "numberOfFrames",
    };
    return (field>=0 && field<2) ? fieldNames[field] : NULL;
}

int P3DBroadcastParameterDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfTimeslots")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfFrames")==0) return base+1;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *P3DBroadcastParameterDescriptor::getFieldTypeString(void *object, int field) const
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

const char *P3DBroadcastParameterDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int P3DBroadcastParameterDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    P3DBroadcastParameter *pp = (P3DBroadcastParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string P3DBroadcastParameterDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    P3DBroadcastParameter *pp = (P3DBroadcastParameter *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNumberOfTimeslots());
        case 1: return long2string(pp->getNumberOfFrames());
        default: return "";
    }
}

bool P3DBroadcastParameterDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    P3DBroadcastParameter *pp = (P3DBroadcastParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumberOfTimeslots(string2long(value)); return true;
        case 1: pp->setNumberOfFrames(string2long(value)); return true;
        default: return false;
    }
}

const char *P3DBroadcastParameterDescriptor::getFieldStructName(void *object, int field) const
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

void *P3DBroadcastParameterDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    P3DBroadcastParameter *pp = (P3DBroadcastParameter *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

