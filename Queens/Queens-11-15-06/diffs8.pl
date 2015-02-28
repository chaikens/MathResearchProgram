#!/usr/bin/perl -w

my $nQueens = 6;
my $ord = 10;
my $piece = "queenx";

my @A;
$A[0] = `./queens --piece $piece --nrows $nQueens --ncols 0`+0;


print "0:$A[0],";
print "\n";

my $i;
my $times = 30;
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
    print "$i:";
    $B[0] = `./queens --piece $piece --nrows $nQueens --ncols $i`+0;
    #$B[0] = $i*$i*$i;
    my $j;
    for( $j = 1; $j <= min($ord,$i) ; $j++ )
    {
	$B[$j] = $B[$j - 1] - $A[$j - 1];
    }
    for( $j = 0; $j <= min($ord,$i); $j++ )
    {
	$A[$j] = $B[$j];
	print "$A[$j],";
    }
    print "\n";
}







