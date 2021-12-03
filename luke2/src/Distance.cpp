#include "Distance.h"

#define JORDENS_RADIUS 6371 // km

// Deg to rand
double Radians(double degrees)
{
    return degrees * M_PI / 360.0;
}

// Finding the distance betweet two points
double DistanceKM(std::vector<double> &north, std::vector<double> &east, int A, int B)
{
    double x_0 = Radians(east[A]);  // Long
    double y_0 = Radians(north[A]); // Lat
    double x_1 = Radians(east[B]);  // Long
    double y_1 = Radians(north[B]); // Lat
    return JORDENS_RADIUS * acos((sin(y_0) * sin(y_1)) + cos(y_0) * cos(y_1) * cos(x_1 - x_0));
}

double Haversine(std::vector<double> &north, std::vector<double> &east, int A, int B) {
    double x_0 = Radians(east[A]);  // Long
    double y_0 = Radians(north[A]); // Lat
    double x_1 = Radians(east[B]);  // Long
    double y_1 = Radians(north[B]); // Lat
    
    // Haversine Formula
    long double dlong = x_1 - x_0;
    long double dlat = y_1 - y_0;
 
    long double ans = pow(sin(dlat / 2), 2) +
                          cos(y_0) * cos(y_1) *
                          pow(sin(dlong / 2), 2);
 
    ans = 2 * asin(sqrt(ans));
    return ans * JORDENS_RADIUS;
}