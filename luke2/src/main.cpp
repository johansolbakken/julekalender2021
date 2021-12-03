#include <iostream>
#include <vector>

#include "CSVReader.h"
#include "MyUtil.h"
#include "BellmanFord.h"

int main()
{
    std::vector<double> north;
    std::vector<double> east;
    std::vector<int> parent;
    std::vector<double> distance;
    std::vector<bool> visited;

    // Start point
    east.push_back(0);
    north.push_back(90);
    GetData(north, east);

    BellmanFord(north, east, parent, distance, visited, 0);

    PrintValues(north, east, parent, distance, visited);

    std::cout << "Svaret er: " << LargestValue(distance) << "km" << std::endl;
}