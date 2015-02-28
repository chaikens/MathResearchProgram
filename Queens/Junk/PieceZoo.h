#include "AttackTester.h"

static class QueenTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      if(P1.col == P2.col) return true;
      if((P1.col - P2.col)==(P1.row - P2.row)) return true;
      if((P1.col - P2.col)==(P2.row - P1.row)) return true;
      //if(P1.row == P2.row) return true;
      return false;
    }
} myQueenTester;

static class RookTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      if(P1.col == P2.col) return true;
      //if(P1.row == P2.row) return true;
      return false;
    }
} myRookTester;
 




static struct A { 
    char *name;
    AttackTester *ptester;
  } Ary [] =
    { {"queen", &myQueenTester},
      {"rook",  &myRookTester } };



//class PieceZoo {
//  public:
  static AttackTester *getp( char * pch)
  {
    for(int i = 0; i < sizeof(Ary)/sizeof(A); i++)
      {
	if(!strcmp( pch, Ary[i].name )) return Ary[i].ptester;
      }
    return NULL;
  }
//};


