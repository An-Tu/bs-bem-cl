type modifier =
  | Bool(string, bool)
  | KeyValue(string, string)
type modifiers = array<modifier>

let make: string => (~elem: string=?, ~mods: array<modifier>=?) => string
let mix: (string, string) => string
