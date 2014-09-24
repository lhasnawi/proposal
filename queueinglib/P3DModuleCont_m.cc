//
// Generated file, do not edit! Created by opp_msgc 4.5 from P3DModuleCont.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "P3DModuleCont_m.h"

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

Register_Class(P3DModuleCont);

P3DModuleCont::P3DModuleCont(const char *name, int kind) : ::cMessage(name,kind)
{
    this->moduleID_var = 0;
    this->moduleName_var = 0;
    this->moduleType_var = 0;
}

P3DModuleCont::P3DModuleCont(const P3DModuleCont& other) : ::cMessage(other)
{
    copy(other);
}

P3DModuleCont::~P3DModuleCont()
{
}

P3DModuleCont& P3DModuleCont::operator=(const P3DModuleCont& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void P3DModuleCont::copy(const P3DModuleCont& other)
{
    this->moduleID_var = other.moduleID_var;
    this->moduleName_var = other.moduleName_var;
    this->moduleType_var = other.moduleType_var;
}

void P3DModuleCont::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->moduleID_var);
    doPacking(b,this->moduleName_var);
    doPacking(b,this->moduleType_var);
}

void P3DModuleCont::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->moduleID_var);
    doUnpacking(b,this->moduleName_var);
    doUnpacking(b,this->moduleType_var);
}

int P3DModuleCont::getModuleID() const
{
    return moduleID_var;
}

void P3DModuleCont::setModuleID(int moduleID)
{
    this->moduleID_var = moduleID;
}

const char * P3DModuleCont::getModuleName() const
{
    return moduleName_var.c_str();
}

void P3DModuleCont::setModuleName(const char * moduleName)
{
    this->moduleName_var = moduleName;
}

int P3DModuleCont::getModuleType() const
{
    return moduleType_var;
}

void P3DModuleCont::setModuleType(int moduleType)
{
    this->moduleType_var = moduleType;
}

class P3DModuleContDescriptor : public cClassDescriptor
{
  public:
    P3DModuleContDescriptor();
    virtual ~P3DModuleContDescriptor();

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

Register_ClassDescriptor(P3DModuleContDescriptor);

P3DModuleContDescriptor::P3DModuleContDescriptor() : cClassDescriptor("queueing::P3DModuleCont", "cMessage")
{
}

P3DModuleContDescriptor::~P3DModuleContDescriptor()
{
}

bool P3DModuleContDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<P3DModuleCont *>(obj)!=NULL;
}

const char *P3DModuleContDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int P3DModuleContDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount(object) : 3;
}

unsigned int P3DModuleContDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *P3DModuleContDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "moduleID",
        "moduleName",
        "moduleType",
    };
    return (field>=0 && field<3) ? fieldNames[field] : NULL;
}

int P3DModuleContDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleID")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleName")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleType")==0) return base+2;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *P3DModuleContDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : NULL;
}

const char *P3DModuleContDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int P3DModuleContDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    P3DModuleCont *pp = (P3DModuleCont *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string P3DModuleContDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    P3DModuleCont *pp = (P3DModuleCont *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getModuleID());
        case 1: return oppstring2string(pp->getModuleName());
        case 2: return long2string(pp->getModuleType());
        default: return "";
    }
}

bool P3DModuleContDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    P3DModuleCont *pp = (P3DModuleCont *)object; (void)pp;
    switch (field) {
        case 0: pp->setModuleID(string2long(value)); return true;
        case 1: pp->setModuleName((value)); return true;
        case 2: pp->setModuleType(string2long(value)); return true;
        default: return false;
    }
}

const char *P3DModuleContDescriptor::getFieldStructName(void *object, int field) const
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

void *P3DModuleContDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    P3DModuleCont *pp = (P3DModuleCont *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

