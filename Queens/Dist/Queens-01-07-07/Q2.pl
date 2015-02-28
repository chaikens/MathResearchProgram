#!/usr/bin/perl -w

sub plus($)
{
    if( $_[0] < 0 ) {return 0;}
    else 
    { return $_[0]; }
}

my $n;
for( $n = 1; $n <= 20; $n++ )
{
    my $Nu2 = $n*$n 
	- ($n + 2*plus($n-1));
    my $Nqu = `./queens --piece queen --nrows 2 --ncols $n` +0;
    if($Nu2 == $Nqu)
    {
	print "Good for $n Queens: $Nu2\n";
    }
    else
    {   
	print "Whoops: for $n Qneens: Nu2=$Nu2 but counting pgm gives $Nqu!\n";
    }
}
