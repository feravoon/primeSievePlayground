const sieveSize = 1000000;

let passes = 0;
let isPrime = Array(sieveSize+1).fill(0);
let timeLimit = 5.0;

let end, dur;
let start = Date.now();
while(true)
{
    for(let i=0; i<sieveSize; i+=2)
    {
        isPrime[i] = 0;
        isPrime[i+1] = 1;
    }
            
    let step, currNum;

    isPrime[1] = 0;
    isPrime[2] = 1;

    let upperLimit = Math.sqrt(sieveSize);
    for(let i=3; i<=upperLimit; i++)
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
    end = Date.now();
    passes++;
    dur = (end-start)/1000;

    if(dur > timeLimit)
        break;
}

console.log("----------------------------------------------------");
console.log("It ran " + passes + " passes in " + dur + " seconds.");
console.log("Performance: " + passes/dur + " passes/sec");

let primeCount = 0;

for (let i=0; i<=sieveSize; i++)
    primeCount += isPrime[i];

if(primeCount == 78498)
    console.log("And, it's working correctly!");
else
    console.log("But, it's not working correctly!");

console.log("----------------------------------------------------");