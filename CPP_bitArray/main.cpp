#include <math.h>
#include <time.h>
#include <iostream>
#include "bitArray.cpp"

int main()
{
    using namespace std::chrono;
    const unsigned int sieveSize = 1000000;
    bitArray<unsigned char> isPrime(sieveSize);
    
    unsigned int passes = 0;
    float timeLimit = 5.0f;

    duration<float> elapsed_seconds;
    system_clock::time_point end;
    system_clock::time_point start = system_clock::now();

    while(true)
    {        
        isPrime.reset();
        
        int step, currNum;

        isPrime.clearBit(1); // One is not a prime
        isPrime.setBit(2); // Two is a prime

        int upperLimit = (int)sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(isPrime.getBit(i)==1)
            {
                currNum = i*i;
                step = i+i;
                while(currNum <= sieveSize)
                {
                    isPrime.clearBit(currNum);
                    currNum += step;
                }
            }
        }
        end = system_clock::now();
        passes++;
        elapsed_seconds = end-start;
        if(elapsed_seconds.count() >= timeLimit)
            break;
    }
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "It ran " << passes << " passes in " << elapsed_seconds.count() << " seconds." << std::endl;
    std::cout << "Performance: " << passes/elapsed_seconds.count() << " passes/sec" << std::endl;

    // Code below is for checking if the algorithm calculated the result correctly
    unsigned int primeCount = 0;

    for (int i=0; i<=sieveSize; i++)
        primeCount += isPrime.getBit(i);

    if(primeCount==78498)
        std::cout << "And, it's working correctly!" << std::endl;
    else
        std::cout << "But, it's not working correctly!" << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}
