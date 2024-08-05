sieveSize = uint32(1000000);
tic
passes = uint32(0);
while true
    isPrime = true([sieveSize,1]);
    isPrime(2:2:end) = false;

    isPrime(1) = false;
    isPrime(2) = true;
    upperLimit = ceil(sqrt(double(sieveSize)));
    for i=uint32(3:upperLimit)
        if isPrime(i)
            currNum = i*i;
            step = i+i;
            isPrime(currNum:step:end) = false;
        end
    end
    passes = passes + 1;
    timePassed = toc;
    if(timePassed>5)
        break;
    end
end

disp('---------------------------------------------------------')
disp(['It ran ' num2str(passes) ' passes in ' num2str(timePassed) ' seconds.' ])
disp(['Performance: ' num2str(passes/timePassed) ' passes/sec'])

% Checking if the results are correct (this only checks for the last run but we know all the runs produce the same result)
primeCount = 0;

for i = 1:sieveSize
    primeCount = primeCount + isPrime(i);
end

if primeCount==78498
    disp('And, it''s working correctly!!!')
else
    disp('But, it''s not working correctly!!!')
end

disp('---------------------------------------------------------')