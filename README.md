Search & print as much periodic table information as textually possible.

## TODO
- Add element struct objects
- Add periodic table file rows for all elements
- Iterate read() to allow full buffering when file system data is unavailable
- Allow searches or commands
  - Known industrial or other uses
  - Quantum models or at least electron configuration(s) per element
  - Atomic weights, masses, and earthly proportions
  - Applicable formulae
  - Reaction tables or simulations
  - Of course more but consider using a separate program with a database for more complicated information?

## The File: periodictable (deprecated)
Deprecated. Since periodic table information is stable then this program will not need to support writes. Since writes are not necessary reading from a file or database is likely not necessary. Element structures will be used instead. File operations will still be supported mostly for fun and learning low-level IO functions. Use the long option `--ptfile` to search file data instead of structure data.
- Comma separated columns
- LF line separators (disallow windows style carriage return on check-in, see .gitattributes file)
- All byte/character positions known/defined.
- Data is not modified by the program.
- Don't use standard lib (stdio.h) functions at all! (just for fun)

