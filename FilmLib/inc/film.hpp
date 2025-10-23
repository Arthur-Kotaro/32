#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
//#include <filesystem>

//#define USE_GENRES

#ifdef USE_GENRES
enum Genres {
action,       adventure, comedy,
drama,        horror,    thriller,
romance,      science,   fiction,
fantasy,      mystery,   animation,
documentary,  musical,   historical,
war,          western,   superhero,
biographical, family,    sport
};
#endif

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
    std::string countryName;
    std::string filmStudioName;
    unsigned int yearOfProduction;
    Person producer;
    Person director;
    Person writer;
    std::vector<Actor> cast_vec;
#ifdef USE_GENRES
    std::vector<Genres> genres_vec;
    void getGenres();
#endif
    void getFilmDescription();
};