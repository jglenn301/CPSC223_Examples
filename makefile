CC = gcc
CFLAGS = -Wall -std=c17 -pedantic -g

Distance: distance.o more_math.o sphere.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

distance.o: distance.c more_math.h sphere.h
more_math.o: more_math.c more_math.h
sphere.o: sphere.c sphere.h more_math.h

clean:
	rm -f *.o Distance
