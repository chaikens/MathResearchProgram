#include "Board.h"
#include <iostream>

using namespace std;

void Board::enumExts( )
{
  if(ptester->hasUnboundedHorizAttacks())
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
  Place P(1,1);
  if( n() != 0 )
    {
      P = top();
      if( PiecesInOrBelowRow[P.row] == n() )
	{
	  P.row++;
	  P.col = 1;
	}
    }
  while( P.col <= ncols )
    {
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
    cout << sol_count << endl;
}

void Board::print( )
{
      int row, col;
      for( row = nrows; row > 0; row-- )
	{
	  for( col = 1; col <= ncols; col++)
	    //	    if(in(row,col)) cout << '*'; else cout << '0';
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

#include "AttackTester.h"

static void useage()
{
  cerr << "Options:\n\
 --show-boards\n\
 --pieces-per-row n1,n2,n3,...nr [default 1,1,1,...]\n\
 --nrows m  [default 4]\n\
 --ncols n  [default 4]\n\
 --piece queen [default]\n\
 --piece king\n\
 --piece rook  or others added" << endl;
  exit( 1 );
}

int main(int argc, char *argv[])
{
  int nrows=4;
  int ncols=4;
  bool show_boards = false;
  int A[Board::Maxrows];
  bool piecesPerRowGiven = false;
  AttackTester *ptester = getp("queen");
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
      if(!strcmp(*argv,"--pieces-per-row"))
	{
	  char *p = *(++argv);
	  int i;
	  for(i = 0; (i < Board::Maxrows) && *p!='\0'; i++ )
	    {
	      A[i] = strtol(p,&p,0);
	      if( *p == ',' ) p++; else 
		if( *p != '\0' ) useage();
	    }
	  for(      ; i < Board::Maxrows; i++ ) A[i] = 1;
	  piecesPerRowGiven = true;
	  argv++; argc--;
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
      if(!strcmp(*argv,"--piece"))
	{
	  argv++; argc--;
	  ptester = getp(*(argv++));
	  if( !ptester )
	    {
	      cerr << "Unimplemented Piece:" << *(argv - 1) << endl;
	      exit ( 1 );
	    }
	  continue;
	}
    }

  if(piecesPerRowGiven)
    {
      Board myBoard(nrows, ncols, ptester, show_boards, A);
      myBoard.enumExts( );
    }
  else
    {
      Board myBoard(nrows, ncols, ptester, show_boards, NULL );
      myBoard.enumExts( );
    }
  return 0;
}
