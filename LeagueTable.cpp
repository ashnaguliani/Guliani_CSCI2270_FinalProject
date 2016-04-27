#include "LeagueTable.h"
#include <iostream>
#include <fstream>

using namespace std;

LeagueTable::LeagueTable()
{
    head = NULL;
    tail = NULL;
}

LeagueTable::~LeagueTable()
{
    deleteTable();
}
void LeagueTable::addClub(string previousClub, string name, int points, int GP){ //adds a new club to the table
    if(previousClub == "First") //if team to be added is first in the linked list
    {
        club*c = new club(name, 0, points, head, NULL);
        head = c;
    }else{
        club * temp = head;
        while(temp->name != previousClub && temp->next != NULL)
        {
            temp = temp->next;
        }
        club * newClub = new club(name, 0, points, temp->next, temp);
        temp->next = newClub;
    }
}
void LeagueTable::deleteClub(string name){ //delete a club from the standings
    club *delClub = NULL;
    club *searchClub = head;

    bool found = false;

    while(!found and searchClub != NULL){
        if(searchClub->name == name){
            found = true;
        }else{
            searchClub = searchClub->next;
        }
    }
    if(found == true){
        if(searchClub == head){
            delClub = head;
            head = head->next;
            head->prev = NULL;
            delete delClub;
        }else{
            searchClub->prev->next = searchClub->next;
            searchClub->next->prev = searchClub->prev;
            delete searchClub;
        }
    }else{
        cout<<name<<"not found"<<endl;
    }

}
void LeagueTable::deleteTable(){
    club * temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        cout<<"deleting "<<temp->name<<endl;
        delete temp;
    }
}

void LeagueTable::rebalance(string team){
    club *current = head;
    while(current != NULL) //find the current team in the linked list
    {
        if(current->name == team)
        {
            break;
        }
        current = current->next;
    }

    club *temp = current->prev;
    while(temp->prev != NULL) //find the team that current team will be just above (equal or behind on points)
    {
        if(temp->points > current->points)
        {
            break;
        }
        temp = temp->prev;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    if(temp->prev != NULL)
    {
        temp->prev->next = current;
    }
    current->next = temp;
    if(temp->prev == NULL)
    {
        current->prev = NULL;
        head = current;
    }

    current->prev = temp->prev;
    temp->prev = current;

}

void LeagueTable::buildTable(){ //create the table based on teams added
    string EPL16[20] = {"AFC Bournemouth", "Arsenal", "Aston Villa", "Chelsea", "Crystal Palace", "Everton", "Leicester City", "Liverpool", "Manchester City", "Manchester United", "Newcastle United", "Norwich City", "Southampton", "Stoke City", "Sunderland", "Swansea City", "Tottenham Hotspur", "Watford", "West Bromwich Albion", "West Ham United"};
    club *clubAdded; //EPL16 is an array of current teams in the 2016 English League, but can be replaced with any other teams
    club *currentClub;

    for(int i = 0; i < 20; i++){
        if(head == NULL){
            clubAdded = new club(EPL16[i], 0, 0, NULL, NULL);
            currentClub = clubAdded;
            head = currentClub;
        }else{
            clubAdded = new club(EPL16[i], 0, 0, NULL, currentClub);
            currentClub->next = clubAdded;
            currentClub = clubAdded;
        }
    }
    tail = currentClub; //last club added is the tail
}


void LeagueTable::enterScore(string winner, int winningGoals, string loser, int losingGoals){
    club *temp = head;
    club *temp2 = head;
    if(winningGoals < losingGoals) //if the losing team has more goals, input is invalid
    {
        cout << "Invalid Input" << endl;
    }else
    {
        while(temp != NULL) //find the winning team in the linked list
        {
            if(temp->name == winner)
            {
                break;
            }
            temp = temp->next;
        }
        while(temp2 != NULL) //find the losing team in the linked list
        {
            if(temp2->name == loser)
            {
                break;
            }
            temp2 = temp2->next;
        }
        temp->GP = (temp->GP + 1); //both increase games played regardless of outcome
        temp2->GP = (temp2->GP +1);
        if(winningGoals == losingGoals) //in the case of a tie each team gets 1 point
        {
            temp->points = (temp->points + 1);
            temp2->points = (temp2->points + 1);
        }else //winning team gets 3 points, losing teams gets 0
        {
            temp->points = (temp->points + 3);
        }
    }
}

void LeagueTable::printPointsTable(){ //prints a table with each team and their # of points
cout << "==================" << endl;
    club *current = head;
    int place = 1;
    while (current != NULL)
    {
        cout << place <<". " << current->name << " - Points: " << current->points << endl;
        current = current->next;
        place = place+1;
    }
}

void LeagueTable::printGPTable(){ //prints each team and their # of games played
    cout << "==================" << endl;
    club *current = head;
    int place = 1;
    while (current != NULL)
    {
        cout << place <<". " << current->name << " - Games Played : " << current->GP << endl;
        current = current->next;
        place = place+1;
    }
}

void LeagueTable::printAllTable(){ //prints a table with all of each team's statistics
    cout << "==================" << endl;
    club *current = head;
    int place = 1;
    while (current != NULL)
    {
        cout << place <<". " << current->name << " - Games Played : " << current->GP << " - Points: " << current->points <<endl;
        current = current->next;
        place = place+1;
    }
}

void LeagueTable::printStandings(){ //prints only teams standings
    cout << "==================" << endl;
    club *current = head;
    int place = 1;
    while (current != NULL)
    {
        cout << place <<". " << current->name <<endl;
        current = current->next;
        place = place+1;
    }
}
