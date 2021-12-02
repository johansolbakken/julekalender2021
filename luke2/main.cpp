#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <limits>

#include <stdlib.h>

#define JORDENS_RADIUS 6371 //km

// Getting the data from the csv file
void GetData(std::vector<double>& north, std::vector<double>& east) {
    // Creating a filestream
    std::fstream file("cities.csv", std::ios::in);
    
    // Checking if file is open
    if (file.is_open()) {

        // Reading the lines
        std::string line;
        while(std::getline(file, line)) {
            
            // Reading the words of the lines
            std::string word;
            std::stringstream str(line);
            while(std::getline(str, word, ',')) {

                // Checking for Point in line
                std::string point = word.substr(0, 6);
                if (point == "Point(") {
                    // Getting east
                    int i = 0;
                    while (word.substr(6 + i, 1) != " ") i++;
                    //std::cout << word.substr(6, i) << std::endl;
                    east.push_back(atof(word.substr(6, i).c_str()));

                    int j = 6 + i + 1;
                    int k = 0;
                    while (word.substr(j + k, 1) != ")") k++;
                    //std::cout << word.substr(j, k) << std::endl;
                    north.push_back(atof(word.substr(j, k).c_str()));
                }
            }
        }
        file.close();
    }
}

// Finding the distance betweet two points
double Distance(std::vector<double>& north, std::vector<double>& east, int A, int B) {
    double x_0 = east[A];
    double y_0 = north[A];
    double x_1 = east[B];
    double y_1 = north[B];
    return sqrt(pow(x_1 - x_0, 2) + pow(y_1 - y_0, 2));
}

// Relax function
void Relax(std::vector<double>& north, std::vector<double>& east, std::vector<double>& distance, std::vector<int>& parent, int A, int B) {
    double distance_between_AB = Distance(north, east, A, B);
    if (distance[B] > distance[A] + distance_between_AB) {
        distance[B] = distance[A] + distance_between_AB;
        parent[B] = A;
    }
}

// Get smallest value
int SmallestIndex(std::vector<double>& distance, std::vector<bool>& visited) {
    double smallest = std::numeric_limits<double>::infinity();
    int index = 0;

    for (int i = 0; i < distance.size(); i++) {
        if (smallest > distance[i]) {
            if (!visited[i]) {
                smallest = distance[i];
                index = i;
            }
        }
    }

    return index;
}

// Printing values to file
void PrintValues(std::vector<double>& north, std::vector<double>& east, std::vector<int>& parent, std::vector<double>& distance, std::vector<bool>& visited) {
    std::ofstream stream;
    stream.open("result.txt");
    stream << "i\tnorth\teast\tparent\tdistance\tvisited\n";
    for (int i = 0; i < north.size(); i++) {
        stream << i << "\t";
        stream << north[i] << "\t";
        stream << east[i] << "\t";
        stream << parent[i] << "\t";
        stream << distance[i] << "\t";
        stream << visited[i] << "\n";
    }
    stream.close();

}

int main() {
    std::vector<double> north;
    std::vector<double> east;

    // Start point
    east.push_back(0);
    north.push_back(90);
    GetData(north, east);

    std::vector<int> parent;
    std::vector<double> distance;
    std::vector<bool> visited;
    
    // Initialize single source
    for (int i = 0; i < north.size(); i++) {
        parent.push_back(-1);
        distance.push_back(std::numeric_limits<double>::infinity());
        visited.push_back(false);
    }
    distance[0] = 0;

    for (int i = 0; i < north.size(); i++) {
        int index = SmallestIndex(distance, visited);
        for (int j = 0; j < north.size(); j++) {
            if (index == j) continue;
            Relax(north, east, distance, parent, index, j);
        }
        visited[i] = true;
    }

    PrintValues(north, east, parent, distance, visited);

    double greatest_distance = 0;
    int greatest_index = 0;
    for (int i = 0; i < distance.size(); i++) {
        if (greatest_distance < distance[i]) {
            greatest_distance = distance[i];
            greatest_index = i;
        }
    }

    std::cout << "Svaret er: " << (greatest_distance + Distance(north, east, greatest_index, 0)) << "km" << std::endl;
}