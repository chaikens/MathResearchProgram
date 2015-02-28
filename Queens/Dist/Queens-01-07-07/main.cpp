#include "Board.h"
#include "AttackTester.h"
#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

static void useage()
{
  cerr << "Options:\n\
 --show-boards\n\
 --pieces-per-row n1,n2,n3,...nr [default 1,1,1,...]\n\
 --nrows m  [default 4]\n\
 --ncols n  [default 4]\n\
 --piece queen [default]\n\
 Pieces implemented:\n";
  for( char **p = GetPieceList(); *p; p++ )
    cerr << *p << " ";
  cerr << endl;
  exit( 1 );
}

int main(int argc, char *argv[])
{
  int nrows=4;
  int ncols=4;
  bool show_boards = false;
  int A[Board::Maxrows];
  bool piecesPerRowGiven = false;
  AttackTester *ptester = getAttackTesterp("queen");
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
	  ptester = getAttackTesterp(*(argv++));
	  if( !ptester )
	    {
	      cerr << "Unimplemented Piece:" << *(argv - 1) << endl;
	      exit ( 1 );
	    }
	  continue;
	}
      useage();
    }

  if(piecesPerRowGiven)
    {
      Board myBoard(nrows, ncols, ptester, show_boards, A);
      myBoard.enumSols( );
    }
  else
    {
      Board myBoard(nrows, ncols, ptester, show_boards, NULL );
      myBoard.enumSols( );
    }
  return 0;
}
