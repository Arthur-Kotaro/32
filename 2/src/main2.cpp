#include "main2.hpp"
#include "film.hpp"


int main()
{
    std::string fileName = "Films.json";
    std::ifstream file(fileName);
    if (file.is_open())
    {
        nlohmann::json dict;
        file >> dict;
        file.close();

        std::string name, surname;
        std::cout << "Enter actors name and surname to search info: ";
        std::cin >> name >> surname;
//        name = "Kathy";
//        surname = "Bates";
//        name = "Chris";
//        surname = "Evans";
        if(!name.empty() && !surname.empty()) findFilmByKey(dict, name, surname);
    } else std::cout << "ERROR: file \"" << fileName << "\" can\'t be open.\n";
        return 0;
}


bool findFilmByKey(nlohmann::json & _dict, std::string & _name, std::string & _surname)
{
    bool found = false;
    for (nlohmann::json::iterator it = _dict.begin(); it != _dict.end(); ++it)
    {
        for (auto& [index, value] : _dict[it.key()]["cast"].items())
        {
            if(_name == value["name"] && _surname == value["surname"])
            {
                if (!found) std::cout << _name << ' ' << _surname << " starred in ";
                else std::cout << ", ";
                               std:: cout << "film " << it.key() << "in role " << value["role"] << '.' << std::endl;
                found = true;
                break;
            }
        }

#ifdef DEBUG
        std::cout<< "DEBUG: film \"" << it.key() << "\" checked." << std::endl;
#endif
    }
    if(!found) std::cout << "Information about " << _name << ' ' << _surname << ".\n";
    return found;
}