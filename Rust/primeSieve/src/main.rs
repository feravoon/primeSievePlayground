use std::time::{Duration, Instant};

fn main() {
    const SIEVE_SIZE: usize =  1000000;

    let start: Instant = Instant::now();
    let mut end: Instant;
    let mut dur: Duration;
    let mut passes: i32 = 0;
    let mut is_prime = [false; SIEVE_SIZE+1];
    let time_limit: f64 = 5.0;
    loop
    {
        for i in (1..SIEVE_SIZE).step_by(2) {
            is_prime[i] = true;
        }
        
        let mut k: usize;
        let mut curr_num: usize;

        is_prime[0] = false;
        is_prime[1] = false;
        is_prime[2] = false;

        let upper_limit: usize = (SIEVE_SIZE as f32).sqrt() as usize;
        for i in 3..upper_limit
        {
            if is_prime[i]
            {
                k = i;
                loop
                {
                    curr_num = i*k;
                    if curr_num > SIEVE_SIZE
                    {
                        break;
                    }
                    
                    is_prime[curr_num] = false;
                    k = k+2;
                }
            }
        }
        end = Instant::now();
        passes = passes+1;
        dur = end-start;

        if dur.as_secs_f64() > time_limit
        {
            break;
        }
            
    }
    println!("----------------------------------------------------");
    println!("It ran {} passes in {} seconds.", passes, dur.as_secs_f64());
    println!("Performance: {} passes/sec", (passes as f64)/dur.as_secs_f64());
    println!("----------------------------------------------------");
}
