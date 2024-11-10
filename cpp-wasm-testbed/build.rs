extern crate bindgen;
extern crate cc;

use std::env;
use std::path::PathBuf;

fn main() {
    //println!("cargo:rustc-link-lib=c++");
    println!("cargo:rerun-if-changed=hello/hello");

    cc::Build::new()
        .file("hello/hello.cpp")
        //.flag("-std=c++17")
        .include("hello")
        .compile("hello");

    let bindings = bindgen::Builder::default()
        .header("hello/hello.hpp")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
