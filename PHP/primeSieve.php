<?php
$sieveSize = 1000000;
$start = microtime(true);
$passes = 0;
$timeLimit = 5.0;
while(true)
{
    $isPrime = array_fill(0,$sieveSize, 0);
    for($i=1; $i<=$sieveSize; $i+=2)
        $isPrime[$i] = 1;

    $isPrime[0] = 0;
    $isPrime[1] = 0;
    $isPrime[2] = 1;

    $upperLimit = sqrt($sieveSize);
    for($i=3; $i<=$upperLimit; $i++)
    {
        if($isPrime[$i])
        {
            $k = $i;
            while(true)
            {
                $currNum = $i*$k;
                if($currNum>$sieveSize)
                    break;

                $isPrime[$currNum] = 0;
                $k+=2;
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
echo "----------------------------------------------------". PHP_EOL;
?>