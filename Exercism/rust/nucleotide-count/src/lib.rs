use std::collections::HashMap;

pub fn count(of: char, in_str: &str) -> usize {
    in_str.chars()
        .filter(|c| of == *c)
        .count()
}

pub fn nucleotide_counts(of: &str) -> HashMap<char, usize> {
    "ACGT".chars()
        .map(|c| (c, count(c, of)))
        .collect()
}