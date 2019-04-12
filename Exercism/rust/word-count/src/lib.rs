use std::collections::HashMap;

pub fn word_count(in_str: &str) -> HashMap<String, u32> {
    in_str.split(|c: char| !c.is_alphanumeric())
          .filter(|word| !word.is_empty())
          .fold(HashMap::new(), |mut acc, word| {
              *acc.entry(word.to_lowercase()).or_insert(0) += 1;
              acc
          })
}