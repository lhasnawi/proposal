//
// Generated file, do not edit! Created by opp_msgc 4.5 from contFrame.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "contFrame_m.h"

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

Register_Class(ContFrame);

ContFrame::ContFrame(const char *name, int kind) : ::cPacket(name,kind)
{
    this->frameType_var = 0;
    this->moduleName_var = 0;
    this->moduleID_var = 0;
    this->moduleType_var = 0;
}

ContFrame::ContFrame(const ContFrame& other) : ::cPacket(other)
{
    copy(other);
}

ContFrame::~ContFrame()
{
}

ContFrame& ContFrame::operator=(const ContFrame& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ContFrame::copy(const ContFrame& other)
{
    this->frameType_var = other.frameType_var;
    this->moduleName_var = other.moduleName_var;
    this->moduleID_var = other.moduleID_var;
    this->moduleType_var = other.moduleType_var;
}

void ContFrame::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->frameType_var);
    doPacking(b,this->moduleName_var);
    doPacking(b,this->moduleID_var);
    doPacking(b,this->moduleType_var);
}

void ContFrame::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->frameType_var);
    doUnpacking(b,this->moduleName_var);
    doUnpacking(b,this->moduleID_var);
    doUnpacking(b,this->moduleType_var);
}

int ContFrame::getFrameType() const
{
    return frameType_var;
}

void ContFrame::setFrameType(int frameType)
{
    this->frameType_var = frameType;
}

const char * ContFrame::getModuleName() const
{
    return moduleName_var.c_str();
}

void ContFrame::setModuleName(const char * moduleName)
{
    this->moduleName_var = moduleName;
}

int ContFrame::getModuleID() const
{
    return moduleID_var;
}

void ContFrame::setModuleID(int moduleID)
{
    this->moduleID_var = moduleID;
}

int ContFrame::getModuleType() const
{
    return moduleType_var;
}

void ContFrame::setModuleType(int moduleType)
{
    this->moduleType_var = moduleType;
}

class ContFrameDescriptor : public cClassDescriptor
{
  public:
    ContFrameDescriptor();
    virtual ~ContFrameDescriptor();

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

Register_ClassDescriptor(ContFrameDescriptor);

ContFrameDescriptor::ContFrameDescriptor() : cClassDescriptor("queueing::ContFrame", "cPacket")
{
}

ContFrameDescriptor::~ContFrameDescriptor()
{
}

bool ContFrameDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<ContFrame *>(obj)!=NULL;
}

const char *ContFrameDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int ContFrameDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount(object) : 4;
}

unsigned int ContFrameDescriptor::getFieldTypeFlags(void *object, int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *ContFrameDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "frameType",
        "moduleName",
        "moduleID",
        "moduleType",
    };
    return (field>=0 && field<4) ? fieldNames[field] : NULL;
}

int ContFrameDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "frameType")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleName")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleID")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "moduleType")==0) return base+3;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *ContFrameDescriptor::getFieldTypeString(void *object, int field) const
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
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : NULL;
}

const char *ContFrameDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
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

int ContFrameDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    ContFrame *pp = (ContFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string ContFrameDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    ContFrame *pp = (ContFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFrameType());
        case 1: return oppstring2string(pp->getModuleName());
        case 2: return long2string(pp->getModuleID());
        case 3: return long2string(pp->getModuleType());
        default: return "";
    }
}

bool ContFrameDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    ContFrame *pp = (ContFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setFrameType(string2long(value)); return true;
        case 1: pp->setModuleName((value)); return true;
        case 2: pp->setModuleID(string2long(value)); return true;
        case 3: pp->setModuleType(string2long(value)); return true;
        default: return false;
    }
}

const char *ContFrameDescriptor::getFieldStructName(void *object, int field) const
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

void *ContFrameDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    ContFrame *pp = (ContFrame *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}

}; // end namespace queueing

