Buffer & print periodic table file|lines. Provide as much information as textually possible about elements and their relationships to each other.

## Just for fun:
- Don't use standard lib (stdio.h) functions at all!

## The File: periodictable
- Comma separated columns
- LF line separators (disallow windows style carriage return on check-in, see .gitattributes file)
- All byte/character positions known/defined.
- Data is not modified by the program.

## TODO
- Add periodic table file rows for all elements
- Iterate read() to allow full buffering when file system data is unavailable
- Allow searches or commands
  - Known industrial or other uses
  - Quantum models or at least electron configuration(s) per element
  - Atomic weights, masses, and earthly proportions
  - Applicable formulae
  - Reaction tables or simulations
  - Of course more but consider using a separate program with a database for more complicated information?
