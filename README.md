As of Tue Sep 3, we've gotten through the first 4 versions:
* f24_00_no_functions -- the initial version with all code in main
* f24_01_functions -- with code split into main and three functions
* f24_02_constants -- with constants #define-d
* f24_03_separate -- split into main and two libraries, each with implementation (.c) and header (.h)

As it stands now, we compile, link, and run with the commands
```
gcc -c -Wall -std=c17 -pedantic -g distance.c
gcc -c -Wall -std=c17 -pedantic -g sphere.c
gcc -c -Wall -std=c17 -pedantic -g more_math.c
gcc -o Distance -Wall -std=c17 -pedantic -g distance.o sphere.o more_math.o -lm
./Distance
```
On Thursday we'll use a makefile to handle rerunning those commands automatically when we change files and scanf to handle user input.
