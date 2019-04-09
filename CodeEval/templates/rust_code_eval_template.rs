// Reading from program arguments
use std::env;
// File IO stuff
use std::io;
use std::fs::File;
use std::io::prelude::*;
// Other Includes
use std::error::Error;

fn main() {
    // get file input from the program arguments
    // (as the 2nd argument)
    let arg = match env::args().nth(1) {
        Some(arg) => arg,
        None      => panic!("No argument given"),
    };
    println!("input file: {}", arg);

    // Open the file in read only mode
    let mut file = match File::open(&arg) {
        Ok(file) => file,
        Err(why) => panic!("Couldn't open {}: {}", arg,
                           Error::description(&why)),
    };

    // Read the file contents into a string
    let mut s = String::new();
    match file.read_to_string(&mut s) {
        Ok(_) => println!("contents: {}", s),
        Err(why) => panic!("couldn't read {}: {}", arg,
                           Error::description(&why)),
    }
    // 'file' goes out of scope and is closed
}
