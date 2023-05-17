use std::time::{Duration, Instant};

fn main() {
    const SIEVE_SIZE: usize =  1000000;

    let start: Instant = Instant::now();
    let mut end: Instant;
    let mut dur: Duration;
    let mut passes: usize = 0;
    let mut is_prime: [u8; SIEVE_SIZE+1] = [0; SIEVE_SIZE+1];
    //let mut is_prime: Box<[u8; SIEVE_SIZE+1]> = Box::new([0; SIEVE_SIZE+1]);
    let time_limit: f64 = 5.0;
    loop
    {
        is_prime.fill(0);
        for i in (1..SIEVE_SIZE).step_by(2) {
            is_prime[i] = 1;
        }
        
        let mut k: usize;
        let mut curr_num: usize;

        is_prime[0] = 0;
        is_prime[1] = 0;
        is_prime[2] = 1;

        let upper_limit: usize = (SIEVE_SIZE as f32).sqrt() as usize;
        for i in 3..upper_limit
        {
            if is_prime[i]==1
            {
                k = i;
                loop
                {
                    curr_num = i*k;
                    if curr_num > SIEVE_SIZE
                    {
                        break;
                    }
                    
                    is_prime[curr_num] = 0;
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
