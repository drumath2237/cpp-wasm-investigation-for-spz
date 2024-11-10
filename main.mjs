import fs from "node:fs/promises";

const main = async () => {
  const wasmCode = await fs.readFile("./build/hello.wasm");

  const { instance, module } = await WebAssembly.instantiate(wasmCode, {});
  const helloFunc = instance.exports.hello;

  console.log(instance.exports);

  const result = helloFunc();
  console.log(result);
};

main();

