import Module from "./build/main.mjs"

const main = async () => {
  const res = await Module()
console.log(res._hoge);

console.log(res._hoge())
  
};

main();

