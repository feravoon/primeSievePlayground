package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	sieveSize := 1000000

	start := time.Now()
	end := time.Now()
	var dur time.Duration
	passes := 0
	isPrime := make([]uint8, sieveSize+1)
	var timeLimit float64 = 5.0
	for true {
		isPrime = make([]uint8, sieveSize+1)

		for i := 1; i <= sieveSize; i += 2 {
			isPrime[i] = 1
		}

		var currNum int

		isPrime[0] = 0
		isPrime[1] = 0
		isPrime[2] = 1

		upperLimit := int(math.Sqrt(float64(sieveSize)))
		for i := 3; i <= upperLimit; i++ {
			if isPrime[i] == 1 {
				currNum = i * i
				for currNum <= sieveSize {
					isPrime[currNum] = 0
					currNum += i + i
				}
			}
		}
		end = time.Now()
		passes++
		dur = end.Sub(start)

		if dur.Seconds() >= timeLimit {
			break
		}
	}
	fmt.Println("----------------------------------------------------")
	fmt.Println("It ran " + fmt.Sprintf("%d", passes) + " passes in " + fmt.Sprintf("%f", dur.Seconds()) + " seconds.")
	fmt.Println("Performance: " + fmt.Sprintf("%f", float64(passes)/dur.Seconds()) + " passes/sec")

	primeCount := 0

	for i := range isPrime {
		primeCount += int(isPrime[i])
	}
	if primeCount == 78498 {
		fmt.Println("And, it's working correctly!")
	} else {
		fmt.Println("But, it's not working correctly!")
	}

	fmt.Println("----------------------------------------------------")
}
