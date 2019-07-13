type modifier =
  | Bool(string, bool)
  | KeyValue(string, string);
type modifiers = list(modifier);

let make: (string, ~elem: string=?, ~mods: list(modifier)=?, unit) => string;
let mix: (string, string) => string;