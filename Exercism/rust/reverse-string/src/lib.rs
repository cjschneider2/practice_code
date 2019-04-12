/// NOTE: This solution uses the `unicode_segmentation` crate because the
///       `std::str::graphemes()` iterator was removed.
extern crate unicode_segmentation;

use unicode_segmentation::UnicodeSegmentation;

pub fn reverse(input: &str) -> String {
    UnicodeSegmentation::graphemes(input, true).rev().collect()
}
