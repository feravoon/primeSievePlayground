
sieveSize = int32(1000000);
tic
passes = int32(0);
while true
    isPrime = true([sieveSize,1]);
    isPrime(2:2:end) = false;

    isPrime(1) = false;
    isPrime(2) = true;
    upperLimit = ceil(sqrt(double(sieveSize)));
    for i=int32(3:upperLimit)
        if isPrime(i)
            currNum = i*i;
            step = i+i;
            isPrime(currNum:step:sieveSize) = false;
        end
    end
    passes = passes + 1;
    timePassed = toc;
    if(timePassed>5)
        break;
    end
end

disp(['It ran ' num2str(passes) ' passes in ' num2str(timePassed) ' seconds.' ])


myListOfPrimes = find(isPrime).';

listOfPrimes = dlmread('listofPrimes.txt');
listOfPrimes(listOfPrimes>sieveSize) = [];
listOfPrimes(listOfPrimes<=1) = [];

hatalar = [setdiff(listOfPrimes,myListOfPrimes), setdiff(myListOfPrimes,listOfPrimes)];


if isempty(hatalar)
    disp('SUCCESS!!!')
else
    disp('FAIL!!!')
end