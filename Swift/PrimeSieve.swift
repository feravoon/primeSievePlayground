import Swift
import Dispatch

let sieveSize: Int = 1000000;
var isPrime: [UInt8] = Array(repeating: 0, count: sieveSize+1)

var passes: Int = 0;
var timeLimit: Double = 5.0;

let start: DispatchTime = DispatchTime.now();
var end: DispatchTime;
var elapsedSeconds: Double = 0.0;

while(true)
{  
    isPrime.withUnsafeMutableBufferPointer { buffer in

        for i: Int in stride(from: 0, to: sieveSize, by: 2)
        {
            buffer[i] = 0;
            buffer[i+1] = 1;
        }
        buffer[1] = 0;
        buffer[2] = 1;
    
        var step: Int, currNum: Int;
        let upperLimit: Int = Int(sqrt(Double(sieveSize)));
        for i: Int in 3...upperLimit
        {
            if(buffer[i]==1)
            {
                currNum = i*i;
                step = 2*i;
                while(currNum <= sieveSize)
                {
                    buffer[currNum] = 0;
                    currNum += step;
                }
            }
        }
    }
    end = DispatchTime.now();
    passes+=1;
    elapsedSeconds = Double(end.uptimeNanoseconds - start.uptimeNanoseconds) / 1_000_000_000;
    
    if(elapsedSeconds >= timeLimit)
    {
        break;
    }
}
print("----------------------------------------------------");
print("It ran \(passes) passes in \(elapsedSeconds) seconds.");
print("Performance: \(Double(passes)/elapsedSeconds) passes/sec");

// Code below is for checking if the algorithm calculated the result correctly
var primeCount: Int = 0;

for i: Int in 0...sieveSize
{
    primeCount += Int(isPrime[i]);
}
if(primeCount==78498)
{
    print("And, it's working correctly!");
}
else
{
    print("But, it's not working correctly!");
}
    
print("----------------------------------------------------");