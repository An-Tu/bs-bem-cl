type modifier =
  | Bool((string, bool))
  | KeyValue((string, string));

type modifiers = list(modifier);

let elemDivider = "__";
let modDivider = "_";

let formatModifier = (block, ~elem=?, mods) => {
  switch (elem, mods) {
  | (None, Bool((mod_, isActive))) =>
    isActive ? " " ++ block ++ modDivider ++ mod_ : ""
  | (None, KeyValue((key, value))) =>
    " " ++ block ++ modDivider ++ key ++ modDivider ++ value
  | (Some(elem), Bool((mod_, isActive))) =>
    isActive ? " " ++ block ++ elemDivider ++ elem ++ modDivider ++ mod_ : ""
  | (Some(elem), KeyValue((key, value))) =>
    " "
    ++ block
    ++ elemDivider
    ++ elem
    ++ modDivider
    ++ key
    ++ modDivider
    ++ value
  };
};

let rec formatModifiers = (block, ~elem=?, mods) => {
  switch (mods) {
  | [] => ""
  | [mod_, ...rest] =>
    formatModifier(block, ~elem?, mod_)
    ++ formatModifiers(block, ~elem?, rest)
  };
};

let bemCl = (block, ~elem=?, ~mods=?, ()) => {
  switch (elem, mods) {
  | (None, None) => block
  | (Some(elem), None) => block ++ elemDivider ++ elem
  | (None, Some(mods)) => block ++ formatModifiers(block, ~elem?, mods)
  | (Some(elem), Some(mods)) =>
    block ++ elemDivider ++ elem ++ formatModifiers(block, ~elem, mods)
  };
};

let make = block => bemCl(block);

let mix = (firstClass, secondClass) => firstClass ++ " " ++ secondClass;