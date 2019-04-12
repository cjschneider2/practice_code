
trait OutputWithFactor<'a, T> {
    fn output_with_factor(&self, factor: T, output: &'a str) -> &'a str;
}

impl <'a> OutputWithFactor<'a, usize> for usize {
    fn output_with_factor(&self, factor: usize, output: &'a str) -> &'a str{
        if self % factor == 0 {
            output
        } else {
            &""
        }
    }
}

pub fn raindrops(n: usize) -> String {

    let mut out_string = String::new();

    out_string.push_str(n.output_with_factor(3, "Pling"));
    out_string.push_str(n.output_with_factor(5, "Plang"));
    out_string.push_str(n.output_with_factor(7, "Plong"));

    if &out_string == "" {
        n.to_string()
    } else {
        out_string
    }
}
