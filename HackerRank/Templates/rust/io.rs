#![allow(dead_code, unused_variables, unused_imports)]

/// Utility functions for IO in Hackerrank

use std::io;

pub fn read_int() -> i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read_line failed");
    input.trim().parse::<i32>().expect("i32 parse failed")
}

pub fn read_line_as_vec_int() -> Vec<i64> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read_line failed");
    input.trim()
        .split_whitespace()
        .map(|i| i.parse().expect("parse failed"))
        .collect()
}

pub fn str_to_vec_int(text: &str) -> Vec<i64> {
    text.trim()
        .split_whitespace()
        .map(|i| i.parse().expect("parse failed"))
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_str_to_vec_int() {
        let text = "1 2 3 4334 563 2234";
        let res:Vec<i64> = str_to_vec_int(text);
        println!("{:?}", res);
        assert_eq!(6, res.len());
    }
}
