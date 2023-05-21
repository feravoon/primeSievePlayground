import math
import datetime
from primesUpTo1Mil import *

timeLimit = 5 # 5 seconds
start = datetime.datetime.now() # starting time
passes = 0 # pass counter
sieveSize = 1000000

while True:
    
    isPrime = bytearray(b'\x00\x01')*(int(sieveSize/2)+1) # filling the array with alternating 1's and 0's (eliminating even numbers)

    isPrime[1] = 0 # set 1 as not a prime
    isPrime[2] = 1 # set 2 as a prime

    upperLimit = round(math.sqrt(sieveSize))  # the for loop will run until the square root of the size of the sieve
    for i in range(3,upperLimit+1):
        if isPrime[i]:
            currNum = i*i # start elimination with the square of i
            size = sieveSize-currNum + 2
            step = i+i # elimination step size (since we have already eliminated the even numbers, we can jump over them by using 2*i step size)
            isPrime[currNum::step] = b'\x00' * (size//step + bool(size%step)) # the magic line :)

    finish = datetime.datetime.now() # elapsed time
    passes = passes + 1 # count number of passes
    if (finish-start).total_seconds() >= timeLimit: # check if we've reached the time limit
        break # if so, break the loop

# Performance metrics
print("---------------------------------------------------------")
print("It ran " + str(passes) + " passes in " + str((finish-start).total_seconds()) + " seconds.")
print("Performance: " + str(passes/(finish-start).total_seconds()) + " passes/sec")


# Checking if the results are correct (this only checks for the last run but we know all the runs produce the same result)
trueIsPrime = bytearray(b'\x00')*(sieveSize+1)

for i in primeList:
    trueIsPrime[i] = 1

resultsAreCorrect = True
for i in range(sieveSize+1):
    if isPrime[i] != trueIsPrime[i]:
        resultsAreCorrect = False
        break

if resultsAreCorrect:
    print("And, it's working correctly!!!")
else:
    print("But, it's not working correctly!!!")

print("---------------------------------------------------------")
