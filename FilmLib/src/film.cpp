#include "film.hpp"

bool is_digit(char symbol)
{
   if(symbol >= '0' && symbol <= '9') return true;
   else return false;  
}
#ifdef USE_GENRES
bool RepeatInVec(const std::vector<Genres> & _genres_vec, const int & _genre_num)
{
    for(auto i : _genres_vec)
        if(i == (Genres) _genre_num) return true;
    return false;
}
#endif

unsigned int getYear()
{
    unsigned int year;
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    unsigned int currentYear = 1900 + ltm->tm_year;
    while (true)
    {
        std::cout << "Enter a year of production of the film: ";
        std::cin >> year;
        if(year >= 1900 && year <= currentYear) break;
    }
        return year;
}

void Person::getFullName()
{
    std::cout << "Enter name and surname: ";
    std::cin >> name >> surname;
}

void Actor::getActorInfo()
{
    std::cout << "Enter character name: "; 
    std::getline(std::cin,role);
    std::cout << "Who played " << role << "? ";
    getFullName();
}

unsigned int getCast(std::vector<Actor> & _cast_vec)
{
    unsigned int counter;
    std::string command;
    for(counter = 0; true; ++counter)
    {
        std::cout << "Would you like to add an actor in cast list? Enter \"yes\" or \"no\": ";
        std::cin >> command;
        if(command == "yes" || command == "YES"  || command == "Y" || command == "y" )
        {
            Actor tmp;
            tmp.getActorInfo();
            _cast_vec.push_back(tmp);
        } 
        else if(command == "no" || command == "NO" || command == "N" || command == "n") break;
        else continue;
    }
    return counter;
}
#ifdef USE_GENRES
void Film::getGenres()
{
    std::cout << "\nChoose genres. Type numbers of genres and press \"Enter\".\n\n";
    std::cout << "(1) action,\t\t(2) adventure,\t\t(3) comedy,\n(4) drama,\t\t(5) horror,\t\t(6) thriller,\n(7) romance,\t\t(8) science,\t\t(9) fiction,\n(10) fantasy,\t\t(11) mystery,\t\t(12) animation,\n(13) documentary,\t(14) musical,\t\t(15) historical,\n(16) war,\t\t(17) western,\t\t(18) superhero,\n(19) biographical,\t(20) family,\t\t(21) sport\n";
    std::string genresString;
    std::cout << "\nGenres numbers: ";
    getline(std::cin, genresString);
    std::string tmp_string;
    int genre_num;
    for (int i = 0; i < genresString.length(); ++i)
    {
        if (is_digit(genresString[i]))
        {
            tmp_string.erase();
            tmp_string.append(1, genresString[i]);
            int n = i+1;
            while (is_digit(genresString[n]) && n < genresString.length())
            {
                tmp_string.append(1, genresString[n]);
                n++;
            }
            genre_num = std::stoi(tmp_string);
            if(genre_num >=0 && genre_num <= 20)
            {
                if(!RepeatInVec(genres_vec, genre_num))
                    genres_vec.push_back((Genres) genre_num);
            }
            i = n;
        }
    }
}
#endif


void Film::getFilmDescription()
{
    std::cout<< "Enter the film name: ";
    getline(std::cin, filmName);

#ifdef USE_GENRES
    Film::getGenres();
#endif

#if defined USE_GENRES && defined DEBUG
    std::cout << "Genres vector: ";
    for(int i = 0; i < genres_vec.size(); i++) std::cout << genres_vec[i] << ' ';
    std::cout << std::endl;
#endif

    std::cout << "Enter country name: ";
    getline(std::cin, countryName);
    std::cout << "Enter name of film company: ";
    getline(std::cin, filmStudioName);
    std::cout << "Who is a producer?\t";
    producer.getFullName();
    std::cout << "Who is a director?\t";
    director.getFullName();
    std::cout << "Who is writer?\t\t";
    writer.getFullName();
    getCast(cast_vec);
    yearOfProduction = getYear();
}