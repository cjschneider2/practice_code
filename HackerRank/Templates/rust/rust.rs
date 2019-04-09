use std::io;

pub fn read_line_as_vec_int() -> Vec<usize> {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("read_line failed");
    input.trim()
        .split_whitespace()
        .map(|i| i.parse().expect("parse failed"))
        .collect()
}

fn main() {
    let size = *read_line_as_vec_int().get(0).unwrap();
    staircase(size);
}

fn staircase(size: usize) {
    for space in (0..size).rev() {
        let mut line = String::new();
        let hash = size - space;
        for _s in 0..space {
            line.push(' ');
        }
        for _h in 0..hash {
            line.push('#');
        }
        println!("{}", line);
    }
}