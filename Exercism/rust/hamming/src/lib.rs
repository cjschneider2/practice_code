pub fn hamming_distance(strand_a: &str, strand_b: &str) -> Result<u32, &'static str> {
    match strand_a.len() == strand_b.len() {
        false => {
            Err("inputs of different length")
        }
        true  => {
            Ok( strand_a.chars()
                        .zip(strand_b.chars())
                        .filter(|&(x,y)| x != y)
                        .count() as u32
              )
        }
    }
}