#include "FilLeser.h"

// Gettint the data from the file
void GetData(std::string &data) {
    std::ifstream t("input.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    data = buffer.str();
}