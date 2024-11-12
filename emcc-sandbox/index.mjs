import { readFile } from "node:fs/promises";

const main = async () => {
  const wasmBinary = await readFile("./build/main.wasm");

  const { instance } = await WebAssembly.instantiate(wasmBinary);
  const { fib } = instance.exports;

  console.log(fib(20));
};

main();
