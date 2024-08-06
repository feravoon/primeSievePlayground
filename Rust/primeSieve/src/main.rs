use std::time::{Duration, Instant};

fn main() {
    const SIEVE_SIZE: usize = 1000000;
    let start: Instant = Instant::now();
    let mut end: Instant;
    let mut dur: Duration;
    let mut passes: usize = 0;
    let mut is_prime: [u8; SIEVE_SIZE+1] = [0; SIEVE_SIZE+1];
    let time_limit: f64 = 5.0;
    let mut ind: usize;
    loop
    {   
        // Reset the array    
        ind = 0;
        while ind<SIEVE_SIZE
        {
            is_prime[ind] = 0;
            is_prime[ind+1] = 1;
            ind += 2;
        }
        
        is_prime[1] = 0;
        is_prime[2] = 1;

        let upper_limit: usize = (SIEVE_SIZE as f32).sqrt() as usize;
        let mut curr_num: usize;
        let mut step: usize;
        for i in 3..upper_limit
        {
            if is_prime[i] == 1
            {
                curr_num = i*i;
                step = i+i;
                while curr_num <= SIEVE_SIZE
                {  
                    is_prime[curr_num] = 0;
                    curr_num += step;
                }
            }
        }
        end = Instant::now();
        passes += 1;
        dur = end-start;

        if dur.as_secs_f64() >= time_limit
        {
            break;
        }     
    }
    println!("----------------------------------------------------");
    println!("It ran {} passes in {} seconds.", passes, dur.as_secs_f64());
    println!("Performance: {} passes/sec", (passes as f64)/dur.as_secs_f64());

    let mut prime_count: usize = 0;
    for i in 0..SIEVE_SIZE
    {
            prime_count += is_prime[i] as usize;
    }

    if prime_count == 78498
    {
        println!("And, it's working correctly!");
    }
    else
    {
        println!("But, it's not working correctly!");
    }
    
    println!("----------------------------------------------------");
}
