//
// Generated file, do not edit! Created by opp_msgc 4.5 from P3DModuleCont.msg.
//

#ifndef _QUEUEING_P3DMODULECONT_M_H_
#define _QUEUEING_P3DMODULECONT_M_H_

#include <omnetpp.h>

// opp_msgc version check
#define MSGC_VERSION 0x0405
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgc: 'make clean' should help.
#endif

// dll export symbol
#ifndef QUEUEING_API 
#  if defined(QUEUEING_EXPORT)
#    define QUEUEING_API  OPP_DLLEXPORT
#  elif defined(QUEUEING_IMPORT)
#    define QUEUEING_API  OPP_DLLIMPORT
#  else
#    define QUEUEING_API 
#  endif
#endif


namespace queueing {

/**
 * Class generated from <tt>P3DModuleCont.msg</tt> by opp_msgc.
 * <pre>
 * message P3DModuleCont {
 * 	int moduleID;
 *     string moduleName;   
 *     int moduleType;
 * }
 * </pre>
 */
class QUEUEING_API P3DModuleCont : public ::cMessage
{
  protected:
    int moduleID_var;
    opp_string moduleName_var;
    int moduleType_var;

  private:
    void copy(const P3DModuleCont& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const P3DModuleCont&);

  public:
    P3DModuleCont(const char *name=NULL, int kind=0);
    P3DModuleCont(const P3DModuleCont& other);
    virtual ~P3DModuleCont();
    P3DModuleCont& operator=(const P3DModuleCont& other);
    virtual P3DModuleCont *dup() const {return new P3DModuleCont(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getModuleID() const;
    virtual void setModuleID(int moduleID);
    virtual const char * getModuleName() const;
    virtual void setModuleName(const char * moduleName);
    virtual int getModuleType() const;
    virtual void setModuleType(int moduleType);
};

inline void doPacking(cCommBuffer *b, P3DModuleCont& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, P3DModuleCont& obj) {obj.parsimUnpack(b);}

}; // end namespace queueing

#endif // _QUEUEING_P3DMODULECONT_M_H_
