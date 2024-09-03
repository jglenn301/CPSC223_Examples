#include <stdio.h>
#include <math.h>

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
  double prev_lat = 41.2679, prev_lon = -72.8869;
  double curr_lat = 39.1774, curr_lon = -76.6684;

  // compute colatitudes and convert to radians
  double colat1 = 90 - prev_lat;
  colat1 = (3.1415926535897932384 / 180.0) * colat1;
  double colat2 = 90 - curr_lat;
  colat2 = (3.1415926535897932384 / 180.0) * colat2;

  // compute difference in longitudes in radians
  double delta_lon = prev_lon - curr_lon;
  delta_lon = (3.1415926535897932384 / 180.0) * delta_lon;

  // use spherical law of cosines to compute angle
  double x = acos(cos(colat1) * cos(colat2) + sin(colat1) * sin(colat2) * cos(delta_lon));

  // convert radians to arc length by multiplying by radius
  double total_distance = x * 3959;
  
  printf("distance %lf miles\n", total_distance);
}
