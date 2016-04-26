#ifndef LEAGUETABLE_H
#define LEAGUETABLE_H
#include <iostream>

struct club
{
    std::string name;
    int GP; //games played
    int points;
    club *next;
    club *prev;

    club(){}; //default constructor

    club(std::string initName, int initGP, int initPoints, club *initNext, club *initPrevious)
    {
        name = initName;
        GP = initGP;
        points = initPoints;
        next = initNext;
        prev = initPrevious;
    }
};

class LeagueTable
{
    public:
        LeagueTable();
        ~LeagueTable();
        void buildTable();
        void printAllTable();
        void printPointsTable();
        void printGPTable();
        void printStandings();
        void enterScore(std::string, int, std::string, int);
        void addClub(std::string, std::string, int, int);
        void deleteClub(std::string);
        void deleteTable();
        void rebalance(std::string);
    protected:
    private:
        club *head;
        club *tail;
};

#endif // LEAGUETABLE_H
