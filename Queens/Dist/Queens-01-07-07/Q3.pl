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
    my $Nu3 = $n*$n*$n 
	- 3*$n*($n + plus($n-1)+ plus($n-2))
	+ (2*$n + 8*plus($n-1) + 8*plus($n-2) + 4*plus($n-3));
    my $Nqu = `./queens --piece queen --nrows 3 --ncols $n` +0;
    if($Nu3 == $Nqu)
    {
	print "Good for $n Queens: $Nu3\n";
    }
    else
    {   
	print "Whoops: for $n Qneens: Nu3=$Nu3 but counting pgm gives $Nqu!\n";
    }
}
