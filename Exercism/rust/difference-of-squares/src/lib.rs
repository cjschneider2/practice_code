pub fn square_of_sum (input: i64) -> i64 {
    (1..input+1).fold(0, |sum, x| sum + x).pow(2)
}

pub fn sum_of_squares (input: i64) -> i64 {
    (1..input+1).fold(0, |sum, x| sum + x.pow(2))
}


pub fn difference (input: i64) -> i64 {
    (sum_of_squares(input)-square_of_sum(input)).abs()
}