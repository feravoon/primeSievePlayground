package main

import (
	"fmt"
	"math"
	"time"
)

func main() {
	sieveSize := 1000000

	passes := 0
	isPrime := make([]byte, sieveSize+1)
	var timeLimit float64 = 5.0

	var dur time.Duration
	var end time.Time
	var start time.Time = time.Now()

	for true {
		for i := 0; i < sieveSize; i += 2 {
			isPrime[i] = 0
			isPrime[i+1] = 1
		}

		var currNum int
		var step int
		isPrime[1] = 0
		isPrime[2] = 1

		upperLimit := int(math.Sqrt(float64(sieveSize)))
		for i := 3; i <= upperLimit; i++ {
			if isPrime[i] == 1 {
				currNum = i * i
				step = i + i
				for currNum <= sieveSize {
					isPrime[currNum] = 0
					currNum += step
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
