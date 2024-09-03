#include <stdio.h>
#include <math.h>

/**
 * Compile and run with
 *
 * gcc -o Distance -Wall -std=c99 -pedantic -g distance.c -lm
 * ./Distance
 */

/**
 * Declarations of our functions must precede their use. They're written
 * here with Javadoc-style comments.
 */

/**
 * Returns the colatitude of the given latitude.  The colatitude is the
 * degrees from the north pole to the given latitude.
 * 
 * @param lat a double between -90 and 90
 * @return the colatitude
 */
double colatitude(double lat);

/**
 * Returns given angle converted from degrees to radians.
 * 
 * @param a an angle measured in degrees
 * @return the angle in radians
 */
double to_radians(double a);

/**
 * Returns the distance from one point on the surface of a sphere to another,
 * expressed in terms of the sphere's radius (1.0 = 1 radius).
 * 
 * @param lat1 a number between -90.0 and 90.0
 * @param lon1 a number between -180.0 and 180.0
 * @param lat2 a number between -90.0 and 90.0
 * @param lon2 a number between -180.0 and 180.0
 * @return the distance between the specified points
 */
double distance(double lat1, double lon1, double lat2, double lon2);

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
  double prev_lat = 41.2679, prev_lon = -72.8869;
  double curr_lat = 39.1774, curr_lon = -76.6684;

  double total_distance = distance(prev_lat, prev_lon, curr_lat, curr_lon);
  
  // convert radians to arc length by multiplying by radius and output
  printf("distance %lf miles\n", total_distance * 3959);
}


double distance(double lat1, double lon1, double lat2, double lon2)
{
  // compute colatitudes and convert to radians
  double colat1 = colatitude(lat1);
  colat1 = to_radians(colat1);
  double colat2 = colatitude(lat2);
  colat2 = to_radians(colat2);

  // compute difference in longitudes in radians
  double delta_lon = to_radians(lon1 - lon2);

  // use spherical law of cosines to compute angle
  return acos(cos(colat1) * cos(colat2) + sin(colat1) * sin(colat2) * cos(delta_lon));
}


double colatitude(double lat)
{
  return 90 - lat;
}


double to_radians(double a)
{
  return (3.1415926535897932384 / 180.0) * a;
}

