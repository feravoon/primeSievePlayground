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
	isPrime := make([]bool, sieveSize+1)
	var timeLimit float64 = 5.0
	for true {
		for i := 1; i <= sieveSize; i += 2 {
			isPrime[i] = true
		}

		var k, currNum int

		isPrime[0] = false
		isPrime[1] = false
		isPrime[2] = false

		var upperLimit int = int(math.Sqrt(float64(sieveSize)))
		for i := 3; i <= upperLimit; i++ {
			if isPrime[i] {
				k = i
				for true {
					currNum = i * k
					if currNum > sieveSize {
						break
					}

					isPrime[currNum] = false
					k += 2
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
	fmt.Println("----------------------------------------------------")
}
