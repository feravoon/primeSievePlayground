#include <math.h>
#include <time.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include "bitArray.cpp"

void runSieve(int &passes, float &runtime)
{
    using namespace std::chrono;

    passes = 0;
    runtime = 0.0f;
    
    const unsigned int sieveSize = 1000000;
    bitArray<unsigned char> isPrime(sieveSize);

    float timeLimit = 5.0f;
    duration<double> elapsed_seconds;
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
                while(currNum<=sieveSize)
                {
                    isPrime.clearBit(currNum);
                    currNum += step;
                }
            }
        }
        end = system_clock::now();
        passes++;
        elapsed_seconds = end-start;
        if(elapsed_seconds.count() > timeLimit)
            break;
    }
    runtime = elapsed_seconds.count();

    // Code below is for checking if the algorithm calculated the result correctly
    volatile unsigned int primeCount = 0;

    for(int i=2; i<=sieveSize; i++)
        if(isPrime.getBit(i))
            primeCount++;

    std::cout << "Prime count below " << sieveSize << ": " << primeCount << " | ";

    if(primeCount==78498)
        std::cout << "CORRECT!!!\n";
    else
        std::cout << "INCORRECT!!!\n";

    return;
}

std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[0m";
}

int main(int argc, char *argv[])
{ 
    unsigned int N = 8; // Default number of threads

    // Input handling
    if(argc>1)
    {   
        try
        {
            N = std::stoi(argv[1]);   
            if(N<=0)
                throw std::invalid_argument("Invalid number of threads");
        }
        catch(std::invalid_argument e)
        {

            if(!strcmp(e.what(),"Invalid number of threads"))
                std::cout << bold_on << "\x1B[31mError:\033[0m" << bold_off << " Invalid number of threads: '" << argv[1] << "'. Enter a positive integer." << std::endl;
            else if(!strcmp(argv[1],"-help"))
            {
                std::cout << "This program finds all the primes smaller than 1000000 and repeats itself as much as it can for 5 seconds." << std::endl;
                std::cout << "Usage: main <number of threads>, if not given, <number of threads> defaults to 8." << std::endl;
            }
            else
                std::cout << bold_on << "\x1B[31mError:\033[0m" << bold_off << " Unknown parameter '" << argv[1] << "'. Type 'main -help' for usage." << std::endl;
            return 0;
        }
    }


    int* allPasses = new int[N];
    float* allRuntimes = new float[N];
    std::thread threads[N];

    for(int i=0; i<N; i++)
        threads[i] = std::thread(runSieve, std::ref(allPasses[i]), std::ref(allRuntimes[i]));

    for(int i=0; i<N; i++)
        threads[i].join();

    std::cout << "-------------------------------- " << std::endl;
    std::cout << "|  Thread  | Passes | Run Time | " << std::endl;
    std::cout << "|----------|--------|----------| " << std::endl;
    for(int i=0; i<N; i++)
        std::cout << "| Thread " << i << " |  " << allPasses[i] << "  | " << printf("%.5f", allRuntimes[i]) << " |" << std::endl;

    std::cout << "-------------------------------- " << std::endl;
    
    int sumOfAllPasses = 0;

    for(int i=0; i<N; i++)
        sumOfAllPasses += allPasses[i];
    
    std::cout << "Total Passes: " << sumOfAllPasses << std::endl;

    delete[] allPasses;
    delete[] allRuntimes;

    return 0;
}