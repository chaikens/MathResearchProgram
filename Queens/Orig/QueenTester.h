#include "AttackTester.h"

class QueenTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      if(P1.col == P2.col) return true;
      if((P1.col - P2.col)==(P1.row - P2.row)) return true;
      if((P1.col - P2.col)==(P2.row - P1.row)) return true;
      //if(P1.row == P2.row) return true;
      return false;
    }
};
