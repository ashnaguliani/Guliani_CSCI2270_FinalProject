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
        void buildTable(); //initialize the linked list based on array of teams
        void printAllTable(); //prints a table with standings, teams, points, and GP
        void printPointsTable(); //prints a table with teams and points
        void printGPTable(); //prints a table with teams and games played
        void printStandings(); //prints a table with teams and standings
        void enterScore(std::string, int, std::string, int); //enter a score of a game between 2 teams
        void addClub(std::string, std::string, int, int); //add a club to the standings
        void deleteClub(std::string); //delete a club from the standings
        void deleteTable(); //delete the entire table
        void rebalance(std::string); //rebalance the table after a score is added in
    protected:
    private:
        club *head;
        club *tail;
};

#endif // LEAGUETABLE_H
