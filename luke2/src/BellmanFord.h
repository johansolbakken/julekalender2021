#pragma once

#include "Dijkstra.h"

void BellmanFord(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index);