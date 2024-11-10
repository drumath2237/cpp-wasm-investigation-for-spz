use rust_bindgen_testbed::{hello, say};

fn main() {
    let a = unsafe { hello() };
    println!("{}", a);
    unsafe { say() };
}
