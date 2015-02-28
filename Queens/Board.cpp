#include "Board.h"
#include <iostream>

using namespace std;

void Board::enumSols( )
{
  if(ptester->hasUnboundedHorizAttacks())
    //Begin with a feasibility test which eliminates
    //the need to check for horizontal attacks in this case.
    {
      for( int i = 1; i <= nrows; i++ )
	if( PiecesInRow[i] > 1 )
	  {
	    cout << 0 << endl;
	    return;
	  }
    }
  _enumExts();
}

void Board::_enumExts( )
{
  Place P(1,1);  //initialization for 0 pieces already placed.
  if( n() != 0 )
    {
      P = top();//Get place of last piece placed.
      if( PiecesInOrBelowRow[P.row] == n() )
	{
	  //Row holding last piece placed is full.
	  P.row++;
	  P.col = 1;
	}
      //note: more than one piece might be placed in a square.
    }
  while( P.col <= ncols )
    {
      //Will try to place the next piece on or right of last piece.
      if( ! IsAttacked(P) )
        {
	  push(P);
	  if( n() == npieces )
	    report( );
	  else
	    _enumExts( );
	  pop();
	}
      P.col++;
    }
  if( n() == 0 )
    //top-level recursive call about to return: print count.
    cout << sol_count << endl;
}

void Board::print( )
{
      int row, col;
      for( row = nrows; row > 0; row-- )
	{
	  for( col = 1; col <= ncols; col++)
	    //if(in(row,col)) cout << '*'; else cout << '0';
	    if(in(row,col)) cout << '#'; else cout << 'O';
	  cout << endl;
	}
      cout << endl;
}

void Board::report( )
{
  sol_count++;
  if( show_boards )
    {
      cout << "Board " << sol_count << ':' << endl;
      print( );
    }    
}

