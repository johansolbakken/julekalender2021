#include "BellmanFord.h"

void BellmanFord(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index)
{
    InitSingleSource(north, east, parent, distance, visited, 0);

    for (int i = 0; i < north.size(); i++)
    {
        for (int k = 0; k < north.size(); k++)
        {
            for (int j = 0; j < north.size(); j++)
            {
                if (j == i)
                    continue;
                Relax(north, east, distance, parent, k, j);
            }
        }
    }
}