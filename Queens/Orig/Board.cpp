#include "QueenTester.h"
#include "Board.h"
#include <iostream>

using namespace std;

void Board::enumExts(Choices &C )
{
  Place P(1,1);
  if( C.n() != 0 )
    {
      P = C.top();
      if( PiecesInOrBelowRow[P.row] == C.n() )
	{
	  P.row++;
	  P.col = 1;
	}
    }
  while( P.col <= ncols )
    {
      if( ! C.IsAttacked(P) )
        {
	  C.push(P);
	  if( C.n() == npieces )
	    report( C );
	  else
	    enumExts( C );
	  C.pop();
	}
      P.col++;
    }
  if( C.n() == 0 )
    cout << sol_count << endl;
}

void Board::print(Choices& C)
{
      int row, col;
      for( row = nrows; row > 0; row-- )
	{
	  for( col = 1; col <= ncols; col++)
	    if(C.in(row,col)) cout << '*'; else cout << '0';
	  cout << endl;
	}
      cout << endl;
}



void Board::report(Choices& C)
{
  sol_count++;
  if( show_boards )
    {
      cout << "Board " << sol_count << ':' << endl;
      print( C );
    }    
}

int main(int argc, char *argv[])
{
  Choices myChoices(new QueenTester);
  int nrows=4;
  int ncols=4;
  bool show_boards = false;
  argc--;
  argv++;
  while( argc-- )
    {
      if(!strcmp(*argv,"--show-boards"))
	{
	  show_boards = true;
	  argv++;
	  continue;
	}
      if(!strcmp(*argv,"--nrows"))
	{
	  argv++; argc--;
	  nrows=strtol(*(argv++),NULL,0);
	  continue;
	}
      if(!strcmp(*argv,"--ncols"))
	{
	  argv++; argc--;
	  ncols=strtol(*(argv++),NULL,0);
	  continue;
	}
    }
  Board myBoard(nrows, ncols, show_boards);
  myBoard.enumExts(myChoices);
  return 0;
}
