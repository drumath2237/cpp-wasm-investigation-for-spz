import Module from "./build/main.mjs"

const main = async () => {
  const res = await Module()
console.log(res.create_test(10));

console.log(res.hoge())
  
};

main();

