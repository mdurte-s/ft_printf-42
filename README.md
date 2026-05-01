*This project has been created as part of the 42 curriculum by mdurte-s*

# ft_printf

## Description
ft_printf is a custom implementation of the standard C library function `printf`. The goal of this project is to learn how to handle a variable number of arguments in C and to implement a simplified version of `printf` that supports the required conversions. This project focuses on safe formatting, number conversion, and writing output with `write`.

### Features
- `%c` prints a single character.
- `%s` prints a string.
- `%p` prints a pointer value in hexadecimal format.
- `%d` prints a signed decimal integer.
- `%i` prints a signed decimal integer.
- `%u` prints an unsigned decimal integer.
- `%x` prints an unsigned integer in lowercase hexadecimal.
- `%X` prints an unsigned integer in uppercase hexadecimal.
- `%%` prints a literal percent sign.

### Algorithm and Data Structure
The implementation parses the format string sequentially. When a `%` is encountered, the parser identifies the conversion specifier and calls the matching handler.

- `c` and `s` are handled by printing the character or string directly.
- `p` is handled by converting the pointer value to a hexadecimal representation with the `0x` prefix.
- `d` and `i` are handled by converting signed integers to decimal text, including negative signs.
- `u`, `x`, and `X` are handled by converting unsigned integers to the correct base and case.
- `%%` is handled as a literal percent character.

This modular design keeps the code extensible and easier to maintain.

Required Makefile rules: `NAME`, `all`, `clean`, `fclean`, `re`.

The project is written in C and uses the allowed external functions: `write`, `va_start`, `va_arg`, `va_copy`, and `va_end`.

## Instructions
1. Open a terminal in the repository root.
2. Run `make` to compile the library and create `libftprintf.a`.
3. Use `ft_printf` in your test program as needed.

## Resources
- Manual pages;
- Oficial 42 ft_printf Subject;

### AI Usage
AI was used to complement the information given by manual pages and to clarify some extra topics.