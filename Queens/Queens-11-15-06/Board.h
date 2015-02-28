#include "Choices.h"
#include <iostream>
#include <stdlib.h>

class Board {
 public:
  static const int Maxrows = 20;
  //static const int Maxcols = 20;
  void enumSols(  );  //enumerate the solutions
  Board( int nrows, int ncols, AttackTester *ptester,
	 bool show_boards , int A[])
    : C(ptester)
    {
      this->ptester = ptester;
      this->show_boards = show_boards;
      sol_count = 0;
      if((this->nrows = nrows) > Maxrows )
	{
	  std::cerr << nrows << "is too many rows, recompile." << std::endl;
	  exit( 1 );
	}
      //if((this->ncols = ncols) > Maxcols)
      //	{
      //  std::cerr << ncols << "is too many cols, recompile." << std::endl;
      //  exit( 1 );
      //}
	
      this->ncols = ncols;
      this->nrows = nrows;
      npieces = 0;
      for(int i = 1; i <= nrows; i++)
	{
	  npieces += PiecesInRow[i] = (A ? A[i-1] : 1 );  
	  PiecesInOrBelowRow[i] = npieces;
	}
      //Please write another constructor to extend.
    }
 private:
  Choices C;
  int PiecesInRow[Maxrows+1];
  int PiecesInOrBelowRow[Maxrows+1];
  bool show_boards;
  long long int sol_count;
  void report( );  //record the boards state as one solution.
  //the board is printed if show_boards==true
  AttackTester *ptester;
  int nrows;
  int ncols;
  int npieces;
  bool IsAttacked( Place &P )
    { return C.IsAttacked( P ); }
  void _enumExts(  );
  Place& top() { return C.top(); }
  const int& n() { return C.n(); }
  void push(Place &P) { C.push(P); }
  void pop() { C.pop(); }
  const bool in(int& row, int& col ) const { return C.in(row, col); }
  void print(  );  //prints current choices C in the board.
};

