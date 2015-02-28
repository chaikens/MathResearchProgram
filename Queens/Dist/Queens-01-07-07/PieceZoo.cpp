#include "AttackTester.h"
#include <cstring>
using namespace std;

//To add a new piece: 
//First, code a class as follows:
//static class NewPieceTester : public AttackTester {
// public:
//  virtual bool test ( Place &P1, Place &P2 )
//    {
//      //code your attack test here..see examples below
//    }
//  Include the following IF your piece does NOT do unbounded 
//  horizontal attacks:
//  virtual bool hasUnboundedHorizAttacks() 
//    { return false; }
//} myNewPieceTester;
//
//Second, add a line like the one below
//{"newpiece", &myNewPieceTester},
//in the initializer for static struct A Ary[]
//below the tester classes.
//
//Rebuild the whole program and enjoy!

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

static class KnightTester : public AttackTester {
 public:
  virtual bool test( Place &P1, Place &P2 )
    {
      int Dc = P1.col - P2.col;
      int Dr = P1.row - P2.row;
      if( (Dc == 0) && (Dr == 0 ) )  return true;
      if( Dc < 0 ) Dc = -Dc;
      if( Dr < 0 ) Dr = -Dr;
      if( ((Dc == 1) && (Dr ==2 )) || ((Dc == 2) && (Dr == 1)) )
	return true;
      return false;
    }
  virtual bool hasUnboundedHorizAttacks() 
    { return false; }
} myKnightTester;

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
      //{"newpiece", &myNewPieceTester},
      {"knight",  &myKnightTester},
      {"rook",  &myRookTester } };

AttackTester *getAttackTesterp( char * pch )
{
    for(int i = 0; i < sizeof(Ary)/sizeof(A); i++)
      {
	if(!strcmp( pch, Ary[i].name )) return Ary[i].ptester;
      }
    return NULL;
}

char ** GetPieceList( void )
{
  char **temp = new char* [sizeof(Ary)/sizeof(A)+1];
  int i;
  for( i = 0; i < sizeof(Ary)/sizeof(A); i++ )
    temp[i] = Ary[i].name;
  temp[i] = NULL;
  return temp;
}
