Distance: distance.o more_math.o sphere.o
	gcc -o Distance -g distance.o more_math.o sphere.o -lm

distance.o: distance.c more_math.h sphere.h
	gcc -c -Wall -std=c99 -pedantic -g distance.c

more_math.o: more_math.c more_math.h
	gcc -c -Wall -std=c99 -pedantic -g more_math.c

sphere.o: sphere.c sphere.h more_math.h
	gcc -c -Wall -std=c99 -pedantic -g sphere.c
