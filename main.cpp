/*
Author: Ashna Guliani
TA: Guohui Ding
Recitation Section 309, Thursday 9:30 AM
Final Project
Date: April 27, 2016
Acknowledgments: Sean Harrison, Soham Shah, Aaron Pineda, Alex Bertman
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include "LeagueTable.h"

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    bool quit = false;
    int userInput;
    LeagueTable table;

    while (quit != true)
    {
        displayMenu();
        cin >> userInput;

        string clubNew;
        string previousClub;
        string club1;
        string winningClub;
        int winningGoals;
        string losingClub;
        int losingGoals;
        string lose;
        string win;
        string clubNewPoints;
        int newPoints;
        string newClubGP;
        int newGP;

        cin.clear();
        cin.ignore(10000,'\n');

        switch (userInput)
        {
            case 1:
                table.buildTable();
                table.printStandings();
                break;
            case 2:
                table.printPointsTable();
                break;
            case 3:
                table.printGPTable();
                break;
            case 4:
                table.printAllTable();
                break;
            case 5:
                cout << "Enter the winning team, the number of goals they scored, the losing team, and the number of goals they scored." << endl;
                cout << "In the case of a tie, enter either team in any spot." << endl << endl;

                cout << "Enter the winning team: " << endl;
                getline(cin,winningClub);

                cout << "Enter the winning team's number of goals: " << endl;
                getline(cin,win);

                cout << "Enter the losing team: " << endl;
                getline(cin,losingClub);

                cout << "Enter the losing team's number of goals: " << endl;
                getline(cin,lose);

                winningGoals = stoi(win);
                losingGoals = stoi(lose);

                table.enterScore(winningClub, winningGoals, losingClub, losingGoals);

                if(winningGoals == losingGoals)
                {
                    table.rebalance(winningClub);
                    table.rebalance(losingClub);
                }else if(winningGoals > losingGoals)
                {
                    table.rebalance(winningClub);
                }
                break;
            case 6:
                cout << "Enter a club to add: " << endl;
                getline(cin,clubNew);

                cout << "Enter new club's amount of points: " << endl;
                getline(cin, clubNewPoints);
                newPoints = stoi(clubNewPoints);

                cout << "Enter new club's number of games played: " << endl;
                getline(cin, newClubGP);
                newGP = stoi(newClubGP);

                cout << "Enter the club ahead or tied on points: " << endl;
                getline(cin,previousClub);

                table.addClub(previousClub, clubNew, newPoints, newGP);
                break;
            case 7:
                cout << "Enter a club to delete: " << endl;
                getline(cin,club1);

                table.deleteClub(club1);
                break;
            case 8:
                table.deleteTable();
                break;
            case 9:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return 0;
}

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Build Table" << endl;
    cout << "2. Print Points Table" << endl;
    cout << "3. Print Games Played Table" << endl;
    cout << "4. Print All Table" << endl;
    cout << "5. Enter a Game Score" << endl;
    cout << "6. Add Club" << endl;
    cout << "7. Delete Club" << endl;
    cout << "8. Clear Table" << endl;
    cout << "9. Quit" << endl;
    return;
}
