#include <math.h>
#include <time.h>
#include <iostream>
#include "primesUpTo1Mil.h"

int main()
{   
    const int sieveSize = 1000000;
    int start = clock();
    int end;
    int passes = 0;
    char isPrime[sieveSize+1];
    float timeLimit = 5.0;
    while(true)
    {       
        wchar_t val = 0x01000100;
        wmemset((wchar_t *)isPrime,val,sieveSize/4);
        isPrime[sieveSize] = 0;

        int k, currNum;

        isPrime[0] = 0;
        isPrime[1] = 0;
        isPrime[2] = 1;
        
        int upperLimit = sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(isPrime[i])
            {
                k = i;
                while(true)
                {
                    currNum = i*k;
                    if(currNum>sieveSize)
                        break;
                    
                    isPrime[currNum] = 0;
                    k+=2;
                }
            }      
        }
        end = clock();
        passes++;
        if(((float)end - start)/CLOCKS_PER_SEC > timeLimit)
            break;
    }
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "It ran " << passes << " passes in " << ((float)end - start)/CLOCKS_PER_SEC << " seconds." << std::endl;
    std::cout << "Performance: " << passes/(((float)end - start)/CLOCKS_PER_SEC) << " passes/sec" << std::endl;

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
