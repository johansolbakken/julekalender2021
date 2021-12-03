#include "CSVReader.h"

// Getting the data from the csv file
void GetData(std::vector<double> &north, std::vector<double> &east)
{
    // Creating a filestream
    std::fstream file("cities.csv", std::ios::in);

    // Checking if file is open
    if (file.is_open())
    {

        // Reading the lines
        std::string line;
        while (std::getline(file, line))
        {

            // Reading the words of the lines
            std::string word;
            std::stringstream str(line);
            while (std::getline(str, word, ','))
            {

                // Checking for Point in line
                std::string point = word.substr(0, 6);
                if (point == "Point(")
                {
                    // Getting east
                    int i = 0;
                    while (word.substr(6 + i, 1) != " ")
                        i++;
                    // std::cout << word.substr(6, i) << std::endl;
                    east.push_back(atof(word.substr(6, i).c_str()));

                    int j = 6 + i + 1;
                    int k = 0;
                    while (word.substr(j + k, 1) != ")")
                        k++;
                    // std::cout << word.substr(j, k) << std::endl;
                    north.push_back(atof(word.substr(j, k).c_str()));
                }
            }
        }
        file.close();
    }
}