#include "AttackTester.h"
#include <cstring>
using namespace std;

static class QueenTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      if(P1.col == P2.col) return true;
      if((P1.col - P2.col)==(P1.row - P2.row)) return true;
      if((P1.col - P2.col)==(P2.row - P1.row)) return true;
      //if(P1.row == P2.row) return true;
      //Saves time and is ok because hasUnboundedHorizAttacks()
      //will return true.
      return false;
    }
} myQueenTester;

static class RookTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      if(P1.col == P2.col) return true;
      //if(P1.row == P2.row) return true;
      //Saves time and is ok because hasUnboundedHorizAttacks()
      //will return true.
      return false;
    }
} myRookTester;

static class KingTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      return ( (-1 <= P1.col-P2.col) && (P1.col-P2.col <= 1)
	       &&
	       (-1 <= P1.row-P2.row) && (P1.row-P2.row <= 1));
    }
  virtual bool hasUnboundedHorizAttacks() 
    { return false; }
} myKingTester;

static struct A { 
    char *name;
    AttackTester *ptester;
  } Ary [] =
    { {"queen", &myQueenTester},
      {"king",  &myKingTester},
      {"rook",  &myRookTester } };

AttackTester *getAttackTesterp( char * pch )
{
    for(int i = 0; i < sizeof(Ary)/sizeof(A); i++)
      {
	if(!strcmp( pch, Ary[i].name )) return Ary[i].ptester;
      }
    return NULL;
}
