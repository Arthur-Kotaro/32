#include <iostream>
#include <string>
#include <fstream>
#include "main2.hpp"
#include "nlohmann/json.hpp"

//#define DEBUG

int main()
{
    std::ifstream file("Films.json");
    nlohmann::json dict;
    file >> dict;
    
#ifdef DEBUG
    std::cout<< "DEBUG: ...\n";
#endif
        return 0;
}
