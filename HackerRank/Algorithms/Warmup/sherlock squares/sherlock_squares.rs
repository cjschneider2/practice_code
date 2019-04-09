extern crate alg;

#[allow(unused_imports)]
use alg::io;

fn main () {
    let a = 3;
    let b = 9;
    let res = square_cnt_a_b(a, b);
    println!("{:?}", res);
}

/// Returns the number of square integers between the values of 'a' and 'b'
fn square_cnt_a_b(a: u64, b:u64 ) -> usize {
    // boundary definitions: 1 <= A <= B <= 10^9
    if a < b
    || a > 0
    || b < 1_000_000_000
    {
        // calculate root of the smallest sqare greater or eq. to 'a'
        let root = (a as f64).sqrt().ceil() as u64;
        let mut cnt = 0;
        let mut itr = root;
        while itr * itr <= b {
            cnt += 1;
            itr += 1;
        }
        cnt
    } else {
        0
    }
}

#[cfg(test)]
mod tests {
    use super::square_cnt_a_b;

    #[test]
    fn case1() {
        assert_eq!(2, square_cnt_a_b(3, 9));
    }

    #[test]
    fn case2() {
        assert_eq!(0, square_cnt_a_b(17, 24));
    }
}
