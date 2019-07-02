open Jest;

describe("Bc tests 2", () => {
  open Expect;

  let blockName = "some-block";
  let b = Bc.make(blockName);

  test("block name", () =>
    expect(b()) |> toBe(blockName)
  );

  test("add element", () => {
    let elem = "element";
    expect(b(~elem, ())) |> toBe(blockName ++ "__" ++ elem);
  });

  test("add bool modifier - true", () => {
    let mod1 = "mod";
    expect(b(~mods=[Bc.Bool((mod1, true))], ()))
    |> toBe(blockName ++ " " ++ blockName ++ "_" ++ mod1);
  });

  test("add bool modifier - false", () => {
    let mod1 = "mod";
    expect(b(~mods=[Bc.Bool((mod1, false))], ())) |> toBe(blockName);
  });

  test("add key value modifier", () => {
    let key = "key";
    let value = "value";
    expect(b(~mods=[Bc.KeyValue((key, value))], ()))
    |> toBe(blockName ++ " " ++ blockName ++ "_" ++ key ++ "_" ++ value);
  });

  test("add element and key value modifier", () => {
    let elem = "element";
    let key = "key";
    let value = "value";
    expect(b(~elem, ~mods=[Bc.KeyValue((key, value))], ()))
    |> toBe(
         blockName
         ++ "__"
         ++ elem
         ++ " "
         ++ blockName
         ++ "__"
         ++ elem
         ++ "_"
         ++ key
         ++ "_"
         ++ value,
       );
  });

  test("add element and bool modifier - true", () => {
    let elem = "element";
    let mod_ = "mod";
    expect(b(~elem, ~mods=[Bc.Bool((mod_, true))], ()))
    |> toBe(
         blockName
         ++ "__"
         ++ elem
         ++ " "
         ++ blockName
         ++ "__"
         ++ elem
         ++ "_"
         ++ mod_,
       );
  });

  test("add element and bool modifier - fasle", () => {
    let elem = "element";
    let mod_ = "mod";
    expect(b(~elem, ~mods=[Bc.Bool((mod_, false))], ()))
    |> toBe(blockName ++ "__" ++ elem);
  });

  test("add element and modifiers", () => {
    let elem = "element";
    let mod_ = "mod";
    let key = "key";
    let value = "value";
    expect(
      b(
        ~elem,
        ~mods=[Bc.KeyValue((key, value)), Bc.Bool((mod_, true))],
        (),
      ),
    )
    |> toBe(
         blockName
         ++ "__"
         ++ elem
         ++ " "
         ++ blockName
         ++ "__"
         ++ elem
         ++ "_"
         ++ key
         ++ "_"
         ++ value
         ++ " "
         ++ blockName
         ++ "__"
         ++ elem
         ++ "_"
         ++ mod_,
       );
  });
});