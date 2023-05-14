#include <math.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

int getBit(unsigned char bitArray[], int i)
{
    int bitIndex = i%8;
    unsigned char byte = bitArray[i/8];
    unsigned char mask = 0b00000001 << bitIndex;
    byte &= mask;
    return byte>>bitIndex;
}

void setBit(unsigned char bitArray[], int i, int val)
{
    int byteIndex = i/8;
    int bitIndex = i%8;
    unsigned char mask = 0b00000001 << bitIndex;

    bitArray[byteIndex] &= ~mask;
    bitArray[byteIndex] |= val << bitIndex;
}



void runSieve(int &passes, float &runtime)
{
    const int sieveSize = 1000000;
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds;
    unsigned char isPrime[sieveSize/8+1];
    float timeLimit = 5.0;
    while(true)
    {
        unsigned char val = 0b10101010;
        memset(isPrime,val,sieveSize/8+1);
    
        int k, currNum;

        setBit(isPrime,0,0);
        setBit(isPrime,1,0);
        setBit(isPrime,2,1);

        int upperLimit = sqrt(sieveSize);
        for(int i=3; i<=upperLimit; i++)
        {
            if(getBit(isPrime,i))
            {
                k = i;
                while(true)
                {
                    currNum = i*k;
                    if(currNum>sieveSize)
                        break;

                    setBit(isPrime,currNum,0);
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
    {
        threads[i] = std::thread(runSieve, std::ref(allPasses[i]), std::ref(allRuntimes[i]));
    }

    for(int i=0; i<N; i++)
    {
        threads[i].join();
    }

    for(int i=0; i<N; i++)
    {
        std::cout << "Thread " << i << ": " << allPasses[i] << " : " << allRuntimes[i] << std::endl;
    }

    int sumOfAllPasses = 0;

    for(int i=0; i<N; i++)
    {
        sumOfAllPasses += allPasses[i];
    }
    
    std::cout << "Total Passes: " << sumOfAllPasses << std::endl;
    return 0;
}