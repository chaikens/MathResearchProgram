#!/usr/bin/perl -w

my $nQueens = 7; #or other piece, is number of rows in the board.
my $ord = 10;  #max. order of difference to calculate
my $piece = "queen";
my $times = 30;  #number of counts to analyze after the first.

my @A;
$A[0] = `./queens --piece $piece --nrows $nQueens --ncols $nQueens`+0;


print "$nQueens:$A[0]";
print "\n";

my $i;
my @B;

sub min($$)
{
    if( $_[0]<$_[1] )
    { return ($_[0]); }
    else
    { return ($_[1]); }
}

for( $i = 1; $i <= $times; $i++ )
{
    my $n = $i+$nQueens;
    print "$n:";
    $B[0] = `./queens --piece $piece --nrows $nQueens --ncols $n`+0;
    #$B[0] = $i*$i*$i;
    my $j;
    for( $j = 1; $j <= min($ord,$i) ; $j++ )
    {
	$B[$j] = $B[$j - 1] - $A[$j - 1];
    }
    for( $j = 0; $j <= min($ord,$i); $j++ )
    {
	if( $j != 0 ) { print ","; }
	$A[$j] = $B[$j];
	print "$A[$j]";
    }
    print "\n";
}







