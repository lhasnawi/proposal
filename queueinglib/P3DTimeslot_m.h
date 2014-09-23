//
// Generated file, do not edit! Created by opp_msgc 4.5 from P3DTimeslot.msg.
//

#ifndef _QUEUEING_P3DTIMESLOT_M_H_
#define _QUEUEING_P3DTIMESLOT_M_H_

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
 * Class generated from <tt>P3DTimeslot.msg</tt> by opp_msgc.
 * <pre>
 * packet P3DTimeslot {
 *     
 *     int timeslotIndex;
 * 
 *     
 * 
 * }
 * </pre>
 */
class QUEUEING_API P3DTimeslot : public ::cPacket
{
  protected:
    int timeslotIndex_var;

  private:
    void copy(const P3DTimeslot& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const P3DTimeslot&);

  public:
    P3DTimeslot(const char *name=NULL, int kind=0);
    P3DTimeslot(const P3DTimeslot& other);
    virtual ~P3DTimeslot();
    P3DTimeslot& operator=(const P3DTimeslot& other);
    virtual P3DTimeslot *dup() const {return new P3DTimeslot(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getTimeslotIndex() const;
    virtual void setTimeslotIndex(int timeslotIndex);
};

inline void doPacking(cCommBuffer *b, P3DTimeslot& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, P3DTimeslot& obj) {obj.parsimUnpack(b);}

}; // end namespace queueing

#endif // _QUEUEING_P3DTIMESLOT_M_H_
