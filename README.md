# It's just a simple interpreter
As you see, it's just a pretty simple interpreter
to teach myself, per se.

It's not a complete interpreter; Just a calculator.
(cincum is pronounced as in spanish)

# Files and explanations
* `README.md` is readme file
* `Makefile` is build system (gmake)
* `Grammar.BNF` is backus-naur form - interpreter grammar
* `symtbl.(c|h)` is an implementation of a linked lis - The linked list acts as the interpreter symbol table
* `main.(c|h)` is implementation of `Grammar.BNF` and the interpreter, too
* `errorer.(c|h)` is for errors handlings

# Build
if you want to build it, write:
- `make`
after you ensured `gmake` is installed.

A new file, named 'cincum' will be produced

Then run:
- `./cincum`
- `cincum.exe`
depends if you're in in UNIX or Windows, respectively.

# Tutor
To use it - just build (see above section)

Four basic operation, alongside parantheses & precedence are supported:
- `12+(4/2)*4` prints `=:> 20`
Operators `+`&`-` before a value is also supported:
- `-12+(+12)` prints `=:> 0`
* Variables are supported, too, but to little extent:
* * `$var = <expression>` to initialize or change a variable
* * `var` to use it - or - to return it's value
* * note: in examples above:
* * * `var` is any given name. must match the definition:
* * * * `<identifier> ::= <letter> [<letter> | <number>]* `
* * * `<expression>` means a call to `expression()` - things like `12+43`

### a s(a/i)mple program
```
$hello = 1-1+(-10)
hello@
```

# HOW TO HELP?
Please read [TODO](TODO) file and update the program in a way that handles the errors mentioned in the TODO file