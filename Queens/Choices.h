
#include "AttackTester.h"

class Choices {
 public:
  bool IsAttacked( Place& P )
    {
      for( int i = 0; i < topS; i++ )
	if( tester->test(S[i],P) ) return true;
      return false;
    }
  Choices(AttackTester* tester)
    {
      S = new Place[sizeS = 20];
      topS = 0;
      this->tester = tester;
    }
  Place &top() const
    {
      return S[topS-1];
    }
  void push(Place &P )
    {
      if( topS == sizeS ) doubleme();
      S[topS++] = P;
    }
  void pop()
    {
      topS--;
      //assert( topS >= 0 );
    }
  const int& n() const
    {
      return topS;
    }
  const bool in(int& row, int& col) const
    {
      for( int i = 0; i< topS; i++ )
	if( (S[i].row==row) && (S[i].col==col) ) return true;
      return false;
    }

 private:
  Place* S;
  int topS;
  int sizeS;
  AttackTester *tester;
  void doubleme()
    {
      Place* temp = new Place[ sizeS = sizeS*2 ];
      for( int i = 0; i< topS; i++ )
	temp[i] = S[i];
      delete [] S;
      S = temp;
    }
};

