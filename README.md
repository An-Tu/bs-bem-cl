# bs-bem-cl

Simple reimplementation of [BEM class name generator](https://github.com/znamilya/bem-cl) in [ReasonML](https://reasonml.github.io).

## Usage

### get `BemCl` instance

```reason
let b = BemCl.make("button");
```

### create BEM block

```reason
b() /* => "button" */
```

### create BEM elements

```reason
b(~elem="icon", ()) /* => "button__icon" */

b(~elem="text", ()) /* => "button__text" */
```

### create BEM block with key/value modifiers

```reason
b(~mods=[BemCl.KeyValue(("theme", "green"))], ()) /* => "button button_theme_green" */

b(~mods=[BemCl.KeyValue(("theme", "green")), BemCl.KeyValue(("size", "m"))], ()) /* => "button button_theme_green button_size_m" */
```

### create BEM block with bool modifiers

```reason
b(~mods=[BemCl.Bool(("loading", true))], ()) /* => "button button_loading" */

b(~mods=[BemCl.Bool(("loading", false))], ()) /* => "button" */

b(~mods=[BemCl.Bool(("loading", true)), BemCl.Bool(("disabled", true))], ()) /* => "button button_loading button_disabled" */

b(~mods=[BemCl.Bool(("loading", false)), BemCl.Bool(("disabled", true))], ()) /* => "button button_disabled" */
```

### create BEM element with key/value modifiers

```reason
b(~elem="icon", ~mods=[BemCl.KeyValue(("theme", "green"))], ()) /* => "button__icon button__icon_theme_green" */

b(~elem="text", ~mods=[BemCl.KeyValue(("theme", "green")), BemCl.KeyValue(("size", "m"))], ()) /* => "button__text button__text_theme_green button__text_size_m" */
```

### create BEM element with bool modifiers

```reason
b(~elem="icon", ~mods=[BemCl.Bool(("loading", true))], ()) /* => "button__icon button__icon_loading" */

b(~elem="icon", ~mods=[BemCl.Bool(("loading", false))], ()) /* => "button__icon" */

b(~elem="text", ~mods=[BemCl.Bool(("loading", true)), BemCl.Bool(("disabled", true))], ()) /* => "button__text button__text_loading button__text_disabled" */

b(~elem="text", ~mods=[BemCl.Bool(("loading", false)), BemCl.Bool(("disabled", true))], ()) /* => "button__text button__text_disabled" */
```

### you can mix key/value and bool modifiers

```reason
b(~mods=[BemCl.KeyValue(("theme", "green")), BemCl.Bool(("loading", true))], ()) /* => "button button_theme_green button_loading" */

b(
    ~elem="icon",
    ~mods=[
        BemCl.KeyValue(("theme", "green")),
        BemCl.Bool(("loading", false)),
        BemCl.Bool(("disabled", true))],
    ()
) /* => "button__icon button__icon_theme_green button__icon_disabled" */
```
