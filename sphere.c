#include <math.h>

#include "sphere.h"
#include "more_math.h"

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
  return NORTH_POLE_LATITUDE - lat;
}
