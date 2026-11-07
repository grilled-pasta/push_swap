_This project has been created as part of the 42 curriculum by alkonsta_
# ft_printf
A custom implementation of the C standard library's `printf()` function.
## Description
The project focuses on variadic functions, parsing
format strings, converting values into text, and applying formatting
rules.
```c
int	ft_printf(const char *format, ...)
```
### Supported Conversions
- `%c` - Prints a single character
- `%s` - Prints a string
- `%p` - Prints a pointer address in hexadecimal
- `%d` - Prints a signed decimal integer
- `%i` - Prints a signed decimal integer
- `%u` - Prints an unsigned decimal integer
- `%x` - Prints an unsigned hexadecimal integer using lowercase letters
- `%X` - Prints an unsigned hexadecimal integer using uppercase letters
- `%%` - Prints a percent sign
### Supported Flags
- `-` - Left-justify within the given field width
- `+` - Forces a sign even on positive numbers
- ` ` - Inserts a blank space as a sign for positive values
- `#` - Used with `x` or `X` specifiers, the value is preceeded with `0x` or `0X`
- `0` - Left-pads the number with zeroes instead of spaces when **width** is specified
- width **(number)** - Minimum number of characters to be printed. Does not truncate.
- precision **(.number)** 
	- For `d`, `i`, `u`, `x`, `X` - minimum number of digits to be written. If the value is shorter, the result is padded with leading zeroes. Does not truncate. `0` means that no character is written for the value 0.
	- For `s` - Maximum number of characters to be wirtten.
## Instructions
### Compilation
Clone the repository and navigate to the project directory. Build the static library.
#### Makefile Rules
```bash
make 		# build the library
make clean 	# removes object files
make fclean # removes object files and the library
make re 	# performs a clean rebuild
```
### Usage
Include the project header in your source file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "world");
    ft_printf("Number: %+08d\n", 42);
    ft_printf("Hexadecimal: %#x\n", 255);
    return (0);
}
```
Compile and link your program against the library:
```bash
cc main.c -I. -L. -lftprintf -o example
```
Run it:
```bash
./example
```
## Resources
-	[Beej's Guide: Variadic Functions](https://beej.us/guide/bgc/html/split/variadic-functions.html#variadic-functions)
-	[printf Reference](https://cplusplus.com/reference/cstdio/printf/) --- detailed explanation of the specifiers and the flags.
-   [cppreference --- Variadic
    functions](https://cppreference.com/c/variadic) --- variadic
    function mechanisms.
-   [GNU C Language Manual --- Variable Number of
    Arguments](https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Variable-Number-of-Arguments.html)
    --- `va_list` and variadic argument handling.
-   [cppreference --- printf and related
    functions](https://en.cppreference.com/w/c/io/fprintf) --- formatted
    output reference.
-   [cplusplus.com ---
    printf](https://cplusplus.com/reference/cstdio/printf/) ---
    `printf()` reference and conversion specification overview.
-   [Linux man-pages ---
    printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html) ---
    formatted output specification and behaviour.
-   [Stack Overflow --- Why does printf return a
    value?](https://stackoverflow.com/questions/13535557/why-does-printf-return-a-value)
    --- discussion of the return value of `printf()`.
-   [Stack Overflow --- Difference between `%i` and
    `%d`](https://stackoverflow.com/questions/1893490/what-is-the-difference-between-conversion-specifiers-i-and-d-in-formatted-io-f)
    --- discussion of integer conversion specifiers.
-   [Stack Overflow --- `%d` versus
    `%u`](https://stackoverflow.com/questions/1156942/printf-formatting-d-versus-u)
    --- signed and unsigned integer formatting.
-   [Stack Overflow --- Printing a pointer address in
    hexadecimal](https://stackoverflow.com/questions/25211015/using-x-to-print-the-hex-address-contained-in-a-pointer)
    --- discussion of pointer representations and hexadecimal output.
-   [Linux man-pages ---
    errno(3)](https://man7.org/linux/man-pages/man3/errno.3.html) ---
    error reporting through `errno`.
-   [Stack Overflow --- How to set
    errno](https://stackoverflow.com/questions/11699596/how-to-set-errno-value)
    --- discussion of setting and preserving `errno`.
-   [Stack Overflow --- Initializing a struct in accordance with C
    standards](https://stackoverflow.com/questions/330793/how-to-initialize-a-struct-in-accordance-with-c-programming-language-standards)
    --- structure initialization.
## Algorithm

The implementation parses the format string, stores each conversion's
options, and dispatches it to the appropriate formatter. Formatters
apply the required flags, width, and precision, write the result, and
update the total character count.

## Data structures and technical choices

The implementation uses two structures to represent a parsed conversion.

### `t_flags`

Stores the formatting flags as integer fields:

-   `left_justify`
-   `leading_zeroes`
-   `plus`
-   `space`
-   `hashtag`

Keeping the flags together makes the formatting options easy to pass
between the parser and formatter functions.

### `t_specs`

Stores the complete conversion specification:

-   `flags`: the `t_flags` structure.
-   `min_width`: the requested minimum field width.
-   `precision`: the requested precision; `-1` represents an omitted
    precision.
-   `specifier`: the conversion character.

This structure avoids passing each formatting option as a separate
function argument.

### Buffer strategy

Numeric conversions use fixed-size local buffers rather than dynamic
allocation. The maximum output sizes are bounded by the corresponding
integer types and conversion bases. This avoids heap allocation and the
associated allocation-failure and deallocation paths.

The format string is parsed in place through a pointer-to-pointer. This
avoids copying or allocating memory for each conversion specification.

## Notes
- Trailing `%`
```c
ft_printf("Hello%");
```
In this implementation, the trailing % is written as a literal character. This is an implementation choice and should not be treated as a portable guarantee of the standard printf() function.
### AI usage
AI tools were used as supplementary support during development to clarify C concepts, discuss debugging approaches, review implementation choices, and improve the project documentation. Suggestions were evaluated and adapted as needed; the implementation, decisions, and final testing remain the author's responsibility.