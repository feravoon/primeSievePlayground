# primeSievePlayground
I implemented [Sieve of Eratosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes) in different programming languages.  
(Inspired by [davepl](https://github.com/davepl)'s [Primes](https://github.com/PlummersSoftwareLLC/Primes) project. But the codes are neither in the style of nor compatible with it.)

## Results
These result are from my MacBook Air M2

| **Language**    | **Passes in ~5 sec.** | **Passes/Sec** |
|-----------------|-----------------------|----------------|
| C++             | 15428                 | 3085.54        |
| C++ (8 threads) | 56948                 | 11388.33       |
| C#              | 9965                  | 1992.89        |
| Go              | 9644                  | 1928.76        |
| Java            | 7357                  | 1471.25        |
| JavaScript      | 5296                  | 1058.99        |
| MATLAB          | 8159                  | 1631.64        |
| Perl            | 57                    | 11.34          |
| PHP             | 296                   | 59.06          |
| Python          | 9316                  | 1863.07        |
| Rust            | 15624                 | 3124.69        |
| Swift           | 15976                 | 3195.15        |

    CPP/
    ----------------------------------------------------
    It ran 15428 passes in 5.0001 seconds.
    Performance: 3085.54 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    CPP_multiThread/
    ----------------------------------------------------
    It ran 56948 passes in 5.000557 seconds.
    Performance: 11388.33 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    CSharp/
    ----------------------------------------------------
    It ran 9965 passes in 5.000268 seconds.
    Performance: 1992.8931809255023 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    Go/
    ----------------------------------------------------
    It ran 9644 passes in 5.000097 seconds.
    Performance: 1928.762662 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    Java/
    ----------------------------------------------------
    It ran 7357 passes in 5.000525 seconds.
    Performance: 1471.245519220482 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    JavaScript/
    ----------------------------------------------------
    It ran 5296 passes in 5.001 seconds.
    Performance: 1058.988202359528 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    MATLAB/
    ----------------------------------------------------
    It ran 8159 passes in 5.0005 seconds.
    Performance: 1631.64 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    Perl/
    ----------------------------------------------------
    It ran 57 passes in 5.02562594413757 seconds.
    Performance: 11.3418707706432 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    PHP/
    ----------------------------------------------------
    It ran 296 passes in 5.0116150379181 seconds.
    Performance: 59.062796675413 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    Python/
    ----------------------------------------------------
    It ran 9316 passes in 5.000342 seconds.
    Performance: 1863.0725658364968 passes/sec
    And, it's working correctly!!!
    ----------------------------------------------------

    Rust/
    ----------------------------------------------------
    It ran 15624 passes in 5.000176834 seconds.
    Performance: 3124.6894897317543 passes/sec
    And, it's working correctly!
    ----------------------------------------------------

    Swift/
    ----------------------------------------------------
    It ran 15976 passes in 5.000077375 seconds.
    Performance: 3195.1505550451607 passes/sec
    And, it's working correctly!
    ----------------------------------------------------
