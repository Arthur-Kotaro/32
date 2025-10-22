#pragma once
#include <iostream>
#include <vector>
#include <string>

enum Genres {
action,       adventure, comedy,
drama,        horror,    thriller,
romance,      science,   fiction,
fantasy,      mystery,   animation,
documentary,  musical,   historical,
war,          western,   superhero,
biographical, family,    sport
};

struct Person
{
    std::string name;
    std::string surname;
    void getFullName();
};

struct Actor : Person
{
    std::string role;
    void getActorInfo();
};

struct Film
{
    std::string filmName;
    std::vector<Genres> genres_vec;
    std::string countryName;
    unsigned int yearOfProduction;
    
    std::string filmStudioName;
    Person producer;
    Person director;
    Person writer;
    std::vector<Actor> castList;

    void getFilmDescription();

};


