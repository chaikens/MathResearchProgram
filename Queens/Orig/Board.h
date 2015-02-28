#include "Choices.h"
#include <iostream>

class Board {
 public:
  static const int Maxrows = 20;
  static const int Maxcols = 20;
  int PiecesInRow[Maxrows+1];
  int PiecesInOrBelowRow[Maxrows+1];
  bool show_boards;
  int sol_count;
  void report( Choices& );
  Board( int nrows, int ncols, bool show_boards = false)
    {
      this->show_boards = show_boards;
      sol_count = 0;
      if((this->nrows = nrows) > Maxrows )
	{
	  std::cerr << nrows << "is too many rows, recompile." << std::endl;
	  exit( 1 );
	}
      if((this->ncols = ncols) > Maxcols)
	{
	  std::cerr << ncols << "is too many cols, recompile." << std::endl;
	  exit( 1 );
	}
	
      this->ncols = ncols;
      this->nrows = nrows;
      npieces = 0;
      for(int i = 1; i <= nrows; i++)
	{
	  npieces += PiecesInRow[i] = 1;  
	  PiecesInOrBelowRow[i] = npieces;
	}
      //Please write another constructor to extend.
    }
  int nrows;
  int ncols;
  int npieces;
  void enumExts( Choices & );
 private:
  void print( Choices & );
};

