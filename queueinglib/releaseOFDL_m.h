//
// Generated file, do not edit! Created by opp_msgc 4.5 from releaseOFDL.msg.
//

#ifndef _QUEUEING_RELEASEOFDL_M_H_
#define _QUEUEING_RELEASEOFDL_M_H_

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
 * Class generated from <tt>releaseOFDL.msg</tt> by opp_msgc.
 * <pre>
 * message ReleaseOFDL {
 * 	int row;
 * 	int stage;
 * }
 * </pre>
 */
class QUEUEING_API ReleaseOFDL : public ::cMessage
{
  protected:
    int row_var;
    int stage_var;

  private:
    void copy(const ReleaseOFDL& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ReleaseOFDL&);

  public:
    ReleaseOFDL(const char *name=NULL, int kind=0);
    ReleaseOFDL(const ReleaseOFDL& other);
    virtual ~ReleaseOFDL();
    ReleaseOFDL& operator=(const ReleaseOFDL& other);
    virtual ReleaseOFDL *dup() const {return new ReleaseOFDL(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getRow() const;
    virtual void setRow(int row);
    virtual int getStage() const;
    virtual void setStage(int stage);
};

inline void doPacking(cCommBuffer *b, ReleaseOFDL& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, ReleaseOFDL& obj) {obj.parsimUnpack(b);}

}; // end namespace queueing

#endif // _QUEUEING_RELEASEOFDL_M_H_