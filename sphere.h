#ifndef __SPHERE_H__
#define __SPHERE_H__

#define NORTH_POLE_LATITUDE (90.0)

/**
 * Returns the colatitude of the given latitude.  The colatitude is the
 * degrees from the north pole to the given latitude.
 * 
 * @param lat a double between -90 and 90
 * @return the colatitude
 */
double colatitude(double lat);


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

#endif
