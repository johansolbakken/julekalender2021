#pragma once

#include <vector>
#include <fstream>

void PrintValues(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited);
double LargestValue(std::vector<double> &list);