type modifier =
  | Bool(string, bool)
  | KeyValue(string, string)

type modifiers = array<modifier>

let elemDivider = "__"
let modDivider = "_"

let formatModifier = (block, ~elem=?, mods) =>
  switch (elem, mods) {
  | (None, Bool(mod_, isActive)) => isActive ? " " ++ block ++ modDivider ++ mod_ : ""
  | (None, KeyValue(key, value)) => " " ++ block ++ modDivider ++ key ++ modDivider ++ value
  | (Some(elem), Bool(mod_, isActive)) =>
    isActive ? " " ++ block ++ elemDivider ++ elem ++ modDivider ++ mod_ : ""
  | (Some(elem), KeyValue(key, value)) =>
    " " ++ block ++ elemDivider ++ elem ++ modDivider ++ key ++ modDivider ++ value
  }

let formatModifiers = (block, ~elem=?, ~mods, ()) => {
  let acc = ref("")
  for i in 0 to Js.Array.length(mods) - 1 {
    acc := acc.contents ++ formatModifier(block, ~elem?, mods->Js.Array.unsafe_get(i))
  }
  acc.contents
}

let bemCl = (block, ~elem=?, ~mods=?) =>
  switch (elem, mods) {
  | (None, None) => block
  | (Some(elem), None) => block ++ elemDivider ++ elem
  | (None, Some(mods)) => block ++ formatModifiers(block, ~elem?, ~mods, ())
  | (Some(elem), Some(mods)) =>
    block ++ elemDivider ++ elem ++ formatModifiers(block, ~elem, ~mods, ())
  }

let make = block => bemCl(block, ...)

let mix = (firstClass, secondClass) => firstClass ++ " " ++ secondClass
