#ifndef AttackTester_h_included
#define AttackTester_h_included

#include "Place.h"

class AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 ) = 0;  
  virtual bool hasUnboundedHorizAttacks()
    { return true; }
};

AttackTester *getAttackTesterp( char * pch );

#endif

