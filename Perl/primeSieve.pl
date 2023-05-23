use Time::HiRes qw(time);

use constant SIEVE_SIZE => 1000000;
use constant TIME_LIMIT => 5.0;

my $passes = 0;
my @isPrime = (0)x(SIEVE_SIZE+1);


my $end, $dur;
my $start = time();
while()
{
    for $i (0..(SIEVE_SIZE/2))
    {
        $isPrime[2*$i] = 0;
        $isPrime[2*$i+1] = 1;
    }
            
    my $step, $currNum;

    $isPrime[1] = 0;
    $isPrime[2] = 1;

    my $upperLimit = sqrt(SIEVE_SIZE);
    for $i (3..$upperLimit)
    {
        if($isPrime[$i]==1)
        {
            $currNum = $i*$i;
            $step = 2*$i;
            until($currNum > SIEVE_SIZE)
            {
                $isPrime[$currNum] = 0;
                $currNum += $step;
            }
        }
    }
    $end = time();
    $passes++;
    $dur = $end-$start;

    if($dur > TIME_LIMIT)
    {
        last;
    }
}

print("----------------------------------------------------\n");
print("It ran $passes passes in $dur seconds.\n");
print("Performance: " . $passes/$dur . " passes/sec\n");

my $primeCount = 0;

for (my $i=0; $i<=SIEVE_SIZE; $i++)
{    
    $primeCount += $isPrime[$i];
}

if($primeCount == 78498)
{
    print("And, it's working correctly!\n");
}
else
{
    print("But, it's not working correctly!\n");
}

print("----------------------------------------------------\n");