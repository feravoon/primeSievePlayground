let sieveSize: int = 1000000
let mutable isPrime: uint8 array = Array.init (sieveSize+1) (fun (x: int) -> uint8(x % 2))

let mutable passes: int = 0
let timeLimit: double = 5.0

let start: System.DateTime = System.DateTime.Now
let mutable finish: System.DateTime = start
let mutable elapsed_seconds: float = 0.0

while elapsed_seconds <= timeLimit do
    isPrime <- Array.init (sieveSize+1) (fun (x: int) -> uint8(x % 2))
    
    isPrime[1] <- uint8 0 
    isPrime[2] <- uint8 1

    let mutable currNum: int = 0
    let mutable step: int = 0
    let upperLimit: int = int(sqrt(double sieveSize))
    for i in 3..upperLimit do
        if isPrime[i] = uint8 1 then
            currNum <- i*i
            step <- i+i
            while currNum <= sieveSize do
                isPrime[currNum] <- uint8 0
                currNum <- currNum + step

    finish <- System.DateTime.Now
    passes <- passes+1
    elapsed_seconds <- (finish-start).TotalMilliseconds/1000.0
    
printfn("----------------------------------------------------")
printfn "It ran %d in %f seconds." passes elapsed_seconds
printfn "Performance: %f passes/sec" ((float passes)/elapsed_seconds) 

// Code below is for checking if the algorithm calculated the result correctly
let mutable primeCount = 0

for i in 0..sieveSize do

    primeCount <- primeCount + int isPrime[i]

if primeCount = 78498 then
    printfn("And, it's working correctly!")
else
    printfn("But, it's not working correctly!")
    
printfn("----------------------------------------------------")