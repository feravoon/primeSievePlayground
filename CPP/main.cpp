#include <math.h>
#include <time.h>
#include <iostream>

int main()
{
    using namespace std::chrono;
    const unsigned int sieveSize = 1000000;
    unsigned char isPrime[sieveSize+1] = {0};
    
    unsigned int passes = 0;
    float timeLimit = 5.0f;

    duration<float> elapsed_seconds;
    system_clock::time_point end;
    system_clock::time_point start = system_clock::now();

    while(true)
    {
        for(int i=0; i<sieveSize; i+=2)
        {
            isPrime[i] = 0;
            isPrime[i+1] = 1;
        }
        
        isPrime[1] = 0;
        isPrime[2] = 1;

        int step,currNum;
        int upperLimit = (int)sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(isPrime[i]==1)
            {
                currNum = i*i;
                step = i+i;
                while(currNum <= sieveSize)
                {
                    isPrime[currNum] = 0;
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
        primeCount += isPrime[i];

    if(primeCount==78498)
        std::cout << "And, it's working correctly!" << std::endl;
    else
        std::cout << "But, it's not working correctly!" << std::endl;

    std::cout << "----------------------------------------------------" << std::endl;
    return 0;
}
