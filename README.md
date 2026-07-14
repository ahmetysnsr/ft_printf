# ft_printf

`ft_printf` is a custom implementation of the standard `printf` function, written in C as part of the 42 curriculum. It supports the most common format specifiers and returns the number of printed characters, just like the standard function.

## Overview

This implementation focuses on:

- variadic argument handling
- formatted output to standard output
- integer, string, character, pointer, and hexadecimal conversions
- safe error propagation when `write` fails

## Supported conversions

| Specifier | Meaning |
|---|---|
| `%c` | Character |
| `%s` | String |
| `%p` | Pointer |
| `%d` | Signed decimal integer |
| `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Lowercase hexadecimal |
| `%X` | Uppercase hexadecimal |
| `%%` | Literal percent sign |

## Return value

- Returns the number of characters printed on success
- Returns `-1` if the format string is `NULL`
- Returns `-1` if a write error occurs
- Returns `-1` for a trailing `%` with no specifier

## Project structure

```text
ft_printf/
├── ft_printf.c
├── ft_printf.h
├── ft_printf_utils.c
├── ft_putptr.c
└── Makefile
```

## Build

```bash
make
```

This creates `libftprintf.a`.

Common targets:

```bash
make clean
make fclean
make re
```

## Use in another project

Compile with the header and library path:

```bash
cc main.c -I. -L. -lftprintf
```

Example:

```c
ft_printf("Hello %s, number = %d, hex = %x\n", "world", 42, 42);
```

## Implementation notes

- Strings are printed one character at a time through `write(1, ...)`.
- `NULL` strings are printed as `(null)`.
- Null pointers are printed as `(nil)`.
- Hexadecimal and pointer values are converted recursively.
- The code is intentionally minimal and does not implement flags, width, precision, or length modifiers.
