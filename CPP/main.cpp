#include <math.h>
#include <time.h>
#include <iostream>
#include "primesUpTo1Mil.h"

int main()
{
    using namespace std::chrono;
    const unsigned int sieveSize = 1000000;

    system_clock::time_point start = system_clock::now();
    system_clock::time_point end = system_clock::now();
    duration<double> elapsed_seconds;

    unsigned int passes = 0;
    unsigned char isPrime[sieveSize+1];
    float timeLimit = 5.0f;
    while(true)
    {
        wchar_t val = 0x01000100;
        wmemset((wchar_t *)isPrime,val,sieveSize/4);
        isPrime[sieveSize] = 0;

        int currNum;

        isPrime[0] = 0;
        isPrime[1] = 0;
        isPrime[2] = 1;

        int upperLimit = sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(isPrime[i])
            {
                currNum = i*i;
                while(currNum <= sieveSize)
                {
                    isPrime[currNum] = 0;
                    currNum += i+i;
                }
            }
        }
        end = system_clock::now();
        passes++;
        elapsed_seconds = end-start;
        if(elapsed_seconds.count() > timeLimit)
            break;
    }
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "It ran " << passes << " passes in " << elapsed_seconds.count() << " seconds." << std::endl;
    std::cout << "Performance: " << passes/elapsed_seconds.count() << " passes/sec" << std::endl;

    // Code below is for checking if the algorithm calculated the result correctly
    int primeList[sieveSize+1];
    int primeListIndex = 0;

    for(int i=2; i<=sieveSize; i++)
    {
        if(isPrime[i])
        {
            primeList[primeListIndex] = i;
            primeListIndex++;
        }
    }

    bool resultsAreCorrect = true;
    for(int i=0; i<78498; i++)
    {
        if(primeList[i]!=primesControlList[i])
        {
            resultsAreCorrect = false;
            break;
        }
    }

    if((primeListIndex==78498) & resultsAreCorrect)
        std::cout << "And, it's working correctly!" << std::endl;
    else
        std::cout << "But, it's not working correctly!" << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}
