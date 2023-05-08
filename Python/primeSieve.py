import math
import datetime
from primesUpTo1Mil import *

timeLimit = 5;
start = datetime.datetime.now()
passes = 0;
sieveSize = 1000000
while True:
    isPrime = bytearray(b'\x00\x01')*(int(sieveSize/2)+1)

    isPrime[1] = 0
    isPrime[2] = 1

    upperLimit = round(math.sqrt(sieveSize));
    for i in range(3,upperLimit+1):
        if isPrime[i]:
            currNum = i*i
            size = sieveSize-currNum + 2
            step = 2*i
            isPrime[currNum::step] = b'\x00' * (size//step + bool(size%step) )

    finish = datetime.datetime.now()
    passes = passes + 1
    if (finish-start).total_seconds() >= timeLimit:
        break

print("---------------------------------------------------------")
print("It ran  " + str(passes) + " passes in " + str((finish-start).total_seconds()) + " seconds.")
print("Performance: " + str(passes/(finish-start).total_seconds()) + " passes/sec")


trueIsPrime = bytearray(b'\x00')*(sieveSize+1)

for i in primeList:
    trueIsPrime[i] = 1

resultsAreCorrect = True;
for i in range(sieveSize+1):
    if isPrime[i] != trueIsPrime[i]:
        resultsAreCorrect = False
        break

if resultsAreCorrect:
    print("And, it's working correctly!!!")
else:
    print("But, it's not working correctly!!!")

print("---------------------------------------------------------")