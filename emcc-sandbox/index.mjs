import { readFile } from "fs/promises";
import Module from "./build/main.mjs";

const main = async () => {
  const { save_spz, load_spz } = await Module();

  // const buf = save_spz(0);
  // console.log(buf.size());

  // for (let i = 0; i < buf.size();i++)
  // {
  //   console.log(buf.get(i));

  // }

  const gsData = await readFile("./spz/samples/racoonfamily.spz");
  const gaussianCloud = load_spz(new Uint8Array(gsData.buffer));
  console.log(gaussianCloud);
};

main();

