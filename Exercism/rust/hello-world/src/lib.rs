pub fn hello(name: Option<&str>) -> String {
    "Hello, ".to_string() + name.unwrap_or("World") + "!"
}