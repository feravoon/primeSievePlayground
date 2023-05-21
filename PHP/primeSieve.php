<?php
$sieveSize = 1000000;
$start = microtime(true);
$passes = 0;
$timeLimit = 5.0;
$isPrime = array_fill(0,$sieveSize+1, 0);
while(true)
{
    for($i=0; $i<$sieveSize; $i+=2)
    {
        $isPrime[$i] = 0;
        $isPrime[$i+1] = 1;
    }
    $isPrime[0] = 0;
    $isPrime[1] = 0;
    $isPrime[2] = 1;

    $upperLimit = sqrt($sieveSize);
    for($i=3; $i<=$upperLimit; $i++)
    {
        if($isPrime[$i])
        {
            $currNum = $i*$i;
            while($currNum <= $sieveSize)
            {
                $isPrime[$currNum] = 0;
                $currNum+=2*$i;
            }   
        }
    }
    $end = microtime(true);
    $passes++;
    if($end-$start >= 5)
        break;
}
echo "----------------------------------------------------" . PHP_EOL;
echo "It ran " . $passes . " passes in " . ($end - $start) . " seconds.". PHP_EOL;
echo "Performance: " . $passes/($end - $start) . " passes/sec". PHP_EOL;

$primeCount = 0;

for($i=1; $i<=$sieveSize; $i++)
    $primeCount += $isPrime[$i];

if($primeCount==78498)
    echo "And, it's working correctly!" . PHP_EOL;
else
    echo "But, it's not working correctly!" . PHP_EOL;

echo "----------------------------------------------------". PHP_EOL;
?>