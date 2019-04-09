#![allow(unused_variables, unused_mut)]
extern crate alg;

fn main() {
    let vec = vec![1, 2, 3];
    let res = coin_change(4, 3, &vec);
    println!("{:?}", res);
}

fn coin_change(total: usize, num_coins: usize, coins: &[usize]) -> i64 {
    let mut num = [0i64; 256];
    num[0] = 1;
    for idx in 0..num_coins {
        for idy in coins[idx]..total+1 {
            num[idy] = num[idy] + num[idy - coins[idx]];
        }
    }
    num[total]
}

#[cfg(test)]
mod tests {
    use super::coin_change;

    #[test]
    fn case1() {
        let vec = vec![1, 2, 3];
        assert_eq!(4, coin_change(4, 3, &vec));
    }

    #[test]
    fn case2() {
        let vec = vec![2, 5, 3, 6];
        assert_eq!(5, coin_change(10, 4, &vec));
    }

    #[test]
    fn case3() {
        let mut vec = vec![3, 25, 34, 38, 26, 42, 16, 10, 15, 50, 39, 44,
                           36, 29, 22, 43, 20, 27, 9, 30, 47, 13, 40, 33];
        assert_eq!(5621927, coin_change(222, 24, &vec));
    }
    
}
