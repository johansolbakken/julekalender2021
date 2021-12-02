#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

// Gettint the data from the file
void GetData(std::string &data) {
    std::ifstream t("tall.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    data = buffer.str();
}

// Gets the index of the string K in the vector v
int GetIndex(std::vector<std::string>& v, std::string& K)
{
    auto it = find(v.begin(), v.end(), K);

    if (it != v.end())
    {
        return it - v.begin();
    }
    else {
        return -1;
    }
}

// Formats the number from vector index to number
int FormatNumber(int x) {
    return 50 - x;
}

// Creates the vector of strings representing the numbers
void GetNumbers(std::vector<std::string>& numbers) {
    numbers.clear();

    const char* grunnsiffer[9] = {"en", "to", "tre", "fire", "fem", "seks", "sju", "åtte", "ni"};
    const char* tiersiffer[10] = {"ti", "elleve", "tolv", "tretten", "fjorten", "femten", "seksten", "sytten", "atten", "nitten"};
    const char* tiergangen[3] = {"tjue", "tretti", "førti"};

    numbers.push_back(std::string("null"));

    // Add grunntall
    for (int i = 0; i < 9; i++) {
        numbers.push_back(grunnsiffer[i]);
    }

    // Fra 10 til 19
    for (int i = 0; i < 10; i++) {
        numbers.push_back(tiersiffer[i]);
    }

    // Add fra 20-49
    for (int i = 0; i < 3; i++) {
        numbers.push_back(tiergangen[i]);
        for (int j = 0; j < 9; j++) {
            numbers.push_back(std::string(tiergangen[i]) + std::string(grunnsiffer[j]));
        }
    }

    // Add 50
    numbers.push_back("femti");

    std::reverse(numbers.begin(), numbers.end());
}

int main() {
    // Tall og data
    std::vector<std::string> numbers;
    GetNumbers(numbers);
    std::string data;
    GetData(data);

    // Summen
    unsigned long long sum = 0;

    // Hovedindeksen
    for (int i = data.size()-1; i > 0;) {

        // Offset som gjør at vi kan scanne etter tall i vector lista
        for (int j = 10; j >= 1; j--) {

            // Fjerner negativ index til substr
            while (i - j < 0) j--;

            // Henter substring fra data
            std::string sub = data.substr(i - j, j);

            // Verdien til substringen
            int value = GetIndex(numbers, sub);

            // Hvis svaret er negativt finnes ikke sub i numbers
            if (value >= 0) {
                // Plusser på den formaterte summen
                sum += FormatNumber(value);

                // Flytter indeksen med lengden på ordet
                i -= j;

                // Hopper over for (int j) loopen
                break;
            }
        }
    }
    
    // Printer svaret
    std::cout << sum << std::endl;
}