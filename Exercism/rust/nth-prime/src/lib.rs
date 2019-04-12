
fn sieve(max: usize) -> Vec<bool> {
    let mut prime_map = vec![true; max];
    let max_factor = (max as f32).sqrt().floor() as usize;
    for p in 2..max_factor {
        if prime_map[p] == true {
            let mut idx = p * 2;
            while idx < max {
                prime_map[idx] = false;
                idx += p;
            }
        }
    }
    prime_map
}

fn nth_prime(max: usize, map: Vec<bool>) -> Option<u32> {
    let mut count = -2i32;
    for (idx, val) in map.iter().enumerate() {
        if *val == true { count += 1; }
        if count == max as i32 { return Some(idx as u32); }
    }
    None
}

pub fn nth(n: u32) -> Option<u32> {
    if n == 0 { return None; }
    if n == 1 { return Some(2); }

    let est_max = (n * n) as usize;
    let prime_map = sieve(est_max);
    if est_max < 100 {
        let map: Vec<(usize, &bool)> = prime_map.iter().enumerate().collect();
        println!("{:?}", map);
    }
    let nth = nth_prime(n as usize, prime_map).unwrap();
    Some(nth)
}
