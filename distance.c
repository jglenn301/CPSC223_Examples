#include <stdio.h>

#include "more_math.h"
#include "sphere.h"

#define EARTH_RADIUS_MILES (3959)

/**
 * Compile and run with
 *
 * gcc -o Distance -Wall -std=c99 -pedantic -g distance.c more_math.c sphere.c -lm
 * ./Distance
 */

/**
 * Computes the distance of a path given the latitudes and longitudes
 * of the points on the path.  The coordinates are read from standard input
 * and assumed to be in degrees.  The output is the number of points in the
 * path and the total distance using the great circle distance between adjacent
 * points.
 *
 * @version 0.1 2024-09-02
 */
int main()
{
  double prev_lat, prev_lon;
  double curr_lat, curr_lon;

  if (scanf("%lf %lf %lf %lf", &prev_lat, &prev_lon, &curr_lat, &curr_lon) == 4)
    {
      double total_distance = distance(prev_lat, prev_lon, curr_lat, curr_lon);
      
      // convert radians to arc length by multiplying by radius and output
      printf("distance %lf miles\n", total_distance * EARTH_RADIUS_MILES);
  }
}
