#include <stdio.h>

#include "sphere.h"
#include "more_math.h"

/*
 * Compile and run with
 *
 * gcc -o Distance -Wall -std=c99 -pedantic -g distance.c more_math.c -lm
 * ./Distance
 *
 * and then type, for example,
 *
 * 41.2679 -72.8869
 * 39.1774 -76.6684
 */

#define EARTH_RADIUS_MILES (3959)

/**
 * Computes the distance of a path given the latitudes and longitudes
 * of the points on the path.  The coordinates are read from standard input
 * and assumed to be in degrees.  The output is the number of points in the
 * path and the total distance using the great circle distance between adjacent
 * points.
 *
 * @version 0.1 2017-09-01
 */
int main()
{
  double prev_lat, prev_lon;
  double curr_lat, curr_lon;
  size_t n = 0;
  double total_distance = 0.0;
  
  // read coordinates from standard input (which is usually your keyboard)
  // note that & marks the coordinates as (simulated) reference parameters
  while (scanf("%lf %lf", &curr_lat, &curr_lon) == 2)
    {
      n++;
      if (n >= 2)
	{
	  total_distance += (distance(curr_lat, curr_lon, prev_lat, prev_lon)
			     * EARTH_RADIUS_MILES);
	}

      // current point will be previous point in the next iteration
      // (inchworm! in honor of Prof. Roberta Sabin)
      prev_lat = curr_lat;
      prev_lon = curr_lon;
    }
      
  printf("distance %lf miles\n", total_distance);
}
