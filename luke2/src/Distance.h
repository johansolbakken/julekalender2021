#pragma once

#include <vector>
#include <math.h>

double Radians(double degrees);
double DistanceKM(std::vector<double> &north, std::vector<double> &east, int A, int B);
double Haversine(std::vector<double> &north, std::vector<double> &east, int A, int B);