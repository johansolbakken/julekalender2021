#include "MyUtil.h"

// Printing values to file
void PrintValues(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited)
{
    std::ofstream stream;
    stream.open("result.txt");
    stream << "i\tnorth\teast\tparent\tdistance\tvisited\n";
    for (int i = 0; i < north.size(); i++)
    {
        stream << i << "\t";
        stream << north[i] << "\t";
        stream << east[i] << "\t";
        stream << parent[i] << "\t";
        stream << distance[i] << "\t";
        stream << visited[i] << "\n";
    }
    stream.close();
}

// Finds the largest number in vector
double LargestValue(std::vector<double>& list) {
    double largest = 0;
    for (int i = 0; i < list.size(); i++) {
        if (largest <= list[i]) {
            largest = list[i];
        }
    }
    return largest;
}