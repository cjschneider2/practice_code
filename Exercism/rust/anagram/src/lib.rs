fn sort_to_lower(s: &str) -> String {
    let mut chars: Vec<char>
        = s.to_lowercase()
           .chars()
           .collect();
    chars.sort();
    chars.into_iter().collect()
}

pub fn anagrams_for<'a>(in_str: &'a str, with_str: &'a [&str]) -> Vec<&'a str> {
    let sorted_in = sort_to_lower(&in_str);
    let sorted_with: Vec<_> =
        with_str.into_iter()
                .map(|word| sort_to_lower(&word))
                .collect();

    let mut ret = Vec::<&str>::new();

    for (i, val) in sorted_with.iter().enumerate() {
        if &sorted_in == val {
            let with = with_str.get(i).unwrap();
            // A word can't be its own anagram ( case insensitive )
            if &in_str != with
            && in_str.to_lowercase() != with.to_lowercase() {
               ret.push(with);
            }
        }
    }
    ret
}