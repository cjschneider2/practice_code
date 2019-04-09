use std::io;
use alg::io::read_int;

fn main () {
    let num = 12;
    let digits = parse_digits(num);
    println!("{:?}", find_num_divisible_digits(num, digits));
}

fn find_num_divisible_digits(num: i32, digits: Vec<i32>) -> i32 {
    let mut cnt = 0;
    for d in digits {
        if (num % d) == 0 {
            cnt += 1;
        }
    }
    cnt
}

fn parse_digits(num: i32) -> Vec<i32> {

    // find the max # of digits
    let mut num_digits = 0;
    let mut _d = 1;
    for _ in 0..10 {
        if num < _d { break; }
        _d *= 10;
        num_digits += 1;
    }

    // Push all the digits to the vector
    let mut digits = Vec::new();
    let mut _n = num;
    for _ in 0..num_digits {
        let d = _n % 10;
        _n /= 10;
        digits.push(d);
    }

    return digits;
}
