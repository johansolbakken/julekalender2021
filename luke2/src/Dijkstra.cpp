#include "Dijkstra.h"

// Relax function
void Relax(std::vector<double> &north, std::vector<double> &east, std::vector<double> &distance, std::vector<int> &parent, int A, int B)
{
    double distance_between_AB = Haversine(north, east, A, B);
    if (distance[B] > distance[A] + distance_between_AB)
    {
        distance[B] = distance[A] + distance_between_AB;
        parent[B] = A;
    }
}

// Get smallest value
int SmallestIndex(std::vector<double> &distance, std::vector<bool> &visited)
{
    double smallest = std::numeric_limits<double>::infinity();
    int index = 0;

    for (int i = 0; i < distance.size(); i++)
    {
        if (smallest > distance[i])
        {
            if (!visited[i])
            {
                smallest = distance[i];
                index = i;
            }
        }
    }

    return index;
}

void InitSingleSource(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index)
{
    // Initialize single source
    for (int i = 0; i < north.size(); i++)
    {
        parent.push_back(-1);
        distance.push_back(std::numeric_limits<double>::infinity());
        visited.push_back(false);
    }

    distance[start_index] = 0;
}

void Dijkstra(std::vector<double> &north, std::vector<double> &east, std::vector<int> &parent, std::vector<double> &distance, std::vector<bool> &visited, int start_index)
{
    InitSingleSource(north, east, parent, distance, visited, start_index);
    
    for (int i = 0; i < north.size(); i++)
    {
        // Get smallest value
        int index = SmallestIndex(distance, visited);
        // Relax on all edges
        for (int j = 0; j < north.size(); j++)
        {
            if (index == j)
                continue;
            Relax(north, east, distance, parent, index, j);
        }
        visited[i] = true;
    }
}