#include <math.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include "bitArray.cpp"

void runSieve(int &passes, float &runtime)
{
    const int sieveSize = 1000000;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds;
    float timeLimit = 5.0;
    bitArray<uint8_t> isPrime(sieveSize);
    while(true)
    {
        isPrime.reset();
        int k, currNum;

        isPrime.setBit(0,0);
        isPrime.setBit(1,0);
        isPrime.setBit(2,1);

        int upperLimit = sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(isPrime.getBit(i))
            {
                k = i;
                while(true)
                {
                    currNum = i*k;
                    if(currNum>sieveSize)
                        break;

                    isPrime.setBit(currNum,0);
                    k+=2;
                }
            }
        }
        end = std::chrono::system_clock::now();
        passes++;
        elapsed_seconds = end-start;
        if(elapsed_seconds.count() > timeLimit)
            break;
    }
    runtime = elapsed_seconds.count();
    return;
}

int main()
{   
    const int N = 8; // number of threads;
    int allPasses[N];
    float allRuntimes[N];
    memset(allPasses,0,N*sizeof(int));
    memset(allRuntimes,0,N*sizeof(float));
    std::thread threads[N];

    for(int i=0; i<N; i++)
        threads[i] = std::thread(runSieve, std::ref(allPasses[i]), std::ref(allRuntimes[i]));

    for(int i=0; i<N; i++)
        threads[i].join();

    std::cout << "-------------------------------- " << std::endl;
    std::cout << "|  Thread  | Passes | Run Time | " << std::endl;
    std::cout << "|----------|--------|----------| " << std::endl;
    for(int i=0; i<N; i++)
        std::cout << "| Thread " << i << " | " << allPasses[i] << "  | " << printf("%.5f", allRuntimes[i]) << " |" << std::endl;

    std::cout << "-------------------------------- " << std::endl;
    
    int sumOfAllPasses = 0;

    for(int i=0; i<N; i++)
        sumOfAllPasses += allPasses[i];
    
    std::cout << "Total Passes: " << sumOfAllPasses << std::endl;
    return 0;
}