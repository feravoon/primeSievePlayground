# primeSievePlayground
I try prime sieve algorithms in different programming languages.  
(Inspired by [davepl](https://github.com/davepl)'s [Primes](https://github.com/PlummersSoftwareLLC/Primes) project. But the codes are neither in the style of nor compatible with it.)

### TO-DO
- Add result validation to Java, C#, Go and Rust codes
- I now check all the primes up to 1 million for validation. I can also check the number of primes below certain numbers. (like in [Primes](https://github.com/PlummersSoftwareLLC/Primes))

## Results
These result are from my MacBook Air M2

| **Language** | **Passes in ~5 sec.** | **Passes/Sec** |
|--------------|-----------------------|----------------|
| CPP          | 11458                 | 2291.54        |
| C#           | 10198                 | 2039.50        |
| Go           | 9551                  | 1910.05        |
| Java         | 6658                  | 1331.57        |
| MATLAB       | 8159                  | 1631.64        |
| PHP          | 190                   | 37.86          |
| Python       | 9121                  | 1824.17        |
| Rust         | 8503                  | 1700.47        |

    CPP/
    ----------------------------------------------------
    It ran 11458 passes in 5.00012 seconds.
    Performance: 2291.54 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    CSharp/
    ----------------------------------------------------
    It ran 10198 passes in 5.00024 seconds.
    Performance: 2039.502103899013 passes/sec
    ----------------------------------------------------

    Go/
    ----------------------------------------------------
    It ran 9551 passes in 5.000390 seconds.
    Performance: 1910.050825 passes/sec
    ----------------------------------------------------

    Java/
    ----------------------------------------------------
    It ran 6658 passes in 5.000129 seconds.
    Performance: 1331.5656456063432 passes/sec
    ----------------------------------------------------

    MATLAB/
    ----------------------------------------------------
    It ran 8159 passes in 5.0005 seconds.
    SUCCESS!!!
    ----------------------------------------------------

    PHP/
    ----------------------------------------------------
    It ran 190 passes in 5.0190789699554 seconds.
    Performance: 37.855551015904 passes/sec
    ----------------------------------------------------

    Python/
    ----------------------------------------------------
    It ran 9121 passes in 5.000078 seconds.
    Performance: 1824.1715429239302 passes/sec
    And, it's working correctly!!!
    ----------------------------------------------------

    Rust/
    ----------------------------------------------------
    It ran 8503 passes in 5.000387 seconds.
    Performance: 1700.468383747098 passes/sec
    ----------------------------------------------------
