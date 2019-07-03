# bs-bem-cl

Simple reimplementation of [BEM class name generator](https://github.com/znamilya/bem-cl) in [ReasonML](https://reasonml.github.io).

## Installation

```shell
# npm
npm install --save bs-bem-cl

# yarn
yarn add bs-bem-cl
```

Then add it to `bsconfig.json`:

```json
"bs-dependencies": [
  "bs-bem-cl"
]
```

## Usage

Get `BemCl` instance

```reason
let b = Bc.make("button");
```

Create BEM block

```reason
b() /* => "button" */
```

Create BEM elements

```reason
b(~elem="icon", ()) /* => "button__icon" */

b(~elem="text", ()) /* => "button__text" */
```

Create BEM block with key/value modifiers

```reason
b(~mods=[Bc.KeyValue(("theme", "green"))], ()) /* => "button button_theme_green" */

b(
    ~mods=[
        Bc.KeyValue(("theme", "green")),
        Bc.KeyValue(("size", "m"))
    ],
    ()
) /* => "button button_theme_green button_size_m" */
```

Create BEM block with bool modifiers

```reason
b(~mods=[Bc.Bool(("loading", true))], ()) /* => "button button_loading" */

b(~mods=[Bc.Bool(("loading", false))], ()) /* => "button" */

b(
    ~mods=[
        Bc.Bool(("loading", true)),
        Bc.Bool(("disabled", true))
    ],
    ()
) /* => "button button_loading button_disabled" */

b(
    ~mods=[
        Bc.Bool(("loading", false)),
        Bc.Bool(("disabled", true))
    ],
    ()
) /* => "button button_disabled" */
```

Create BEM element with key/value modifiers

```reason
b(
    ~elem="icon",
    ~mods=[Bc.KeyValue(("theme", "green"))],
    ()
) /* => "button__icon button__icon_theme_green" */

b(
    ~elem="text",
    ~mods=[
        Bc.KeyValue(("theme", "green")),
        Bc.KeyValue(("size", "m"))
    ],
    ()
) /* => "button__text button__text_theme_green button__text_size_m" */
```

Create BEM element with bool modifiers

```reason
b(
    ~elem="icon",
    ~mods=[Bc.Bool(("loading", true))],
    ()
) /* => "button__icon button__icon_loading" */

b(
    ~elem="icon",
    ~mods=[Bc.Bool(("loading", false))],
    ()
) /* => "button__icon" */

b(
    ~elem="text",
    ~mods=[
        Bc.Bool(("loading", true)),
        Bc.Bool(("disabled", true))
    ],
    ()
) /* => "button__text button__text_loading button__text_disabled" */

b(
    ~elem="text",
    ~mods=[
        Bc.Bool(("loading", false)),
        Bc.Bool(("disabled", true))
    ],
    ()
) /* => "button__text button__text_disabled" */
```

You can mix key/value and bool modifiers

```reason
b(
    ~mods=[
        Bc.KeyValue(("theme", "green")),
        Bc.Bool(("loading", true))
    ],
    ()
) /* => "button button_theme_green button_loading" */

b(
    ~elem="icon",
    ~mods=[
        Bc.KeyValue(("theme", "green")),
        Bc.Bool(("loading", false)),
        Bc.Bool(("disabled", true))
    ],
    ()
) /* => "button__icon button__icon_theme_green button__icon_disabled" */
```

You can mix different classes

```reason
b(~elem="icon", ())
->Bc.mix("some__class") /* => "button__icon some__class" */
```
