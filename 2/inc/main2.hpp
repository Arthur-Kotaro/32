#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
//#define DEBUG

bool findFilmByKey(nlohmann::json & _dict, std::string & _name, std::string & _surname);