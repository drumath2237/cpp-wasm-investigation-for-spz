import { readFile } from "node:fs/promises";

const main = async () => {
  const wasmBinary = await readFile("./build/main.wasm");

  const { instance } = await WebAssembly.instantiate(wasmBinary);
  const { fib, hoge } = instance.exports;

  console.log(instance.exports);

  console.log(hoge());
};

main();

