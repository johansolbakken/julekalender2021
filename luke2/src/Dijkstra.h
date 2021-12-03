#pragma once

#include <vector>
#include <limits>

#include "Distance.h"

void Relax(std::vector<double> &north, std::vector<double> &east, std::vector<double> &distance, std::vector<int> &parent, int A, int B);
int SmallestIndex(std::vector<double> &distance, std::vector<bool> &visited);
void InitSingleSource(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index);
void Dijkstra(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index);