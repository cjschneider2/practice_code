#![allow(dead_code)]

use std::collections::HashSet;

pub fn is_pangram( input: &str ) -> bool {
    let alphabet = english_alphabet();
    let to_test = input.chars()
        .filter(|c| c.is_alphabetic())
        .map(|c| c.to_lowercase().next().unwrap())
        .collect::<HashSet<char>>();
    let diff: HashSet<_> = alphabet.difference(&to_test).collect();
    if diff.len() == 0 {
        true
    } else {
        false
    }
}

pub fn english_alphabet() -> HashSet<char> {
    (('a' as u8) .. (('z' as u8) +1)).map(|c| c as char).collect()
}