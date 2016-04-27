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
void LeagueTable::addClub(string previousClub, string name, int points, int GP){
    if(previousClub == "First")
    {
        club*c = new club(name, 0, points, head, NULL);
        head = c;
    }else{
        club * tmp = head;
        while(tmp->name != previousClub && tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        club * newClub = new club(name, 0, points, tmp->next, tmp);
        tmp->next = newClub;
    }
}
void LeagueTable::deleteClub(string nameIn){
    club *delClub = NULL;
    club *searchClub = head;

    bool found = false;

    while(!found and searchClub != NULL){
        if(searchClub->name == nameIn){
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
        cout<<nameIn<<"not found"<<endl;
    }

}
void LeagueTable::deleteTable(){
    club * tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        cout<<"deleting "<<tmp->name<<endl;
        delete tmp;
    }
}

void LeagueTable::rebalance(string team){
    club *current = head;
    while(current != NULL)
    {
        if(current->name == team)
        {
            break;
        }
        current = current->next;
    }

}

void LeagueTable::buildTable(){
    string EPL16[20] = {"AFC Bournemouth", "Arsenal", "Aston Villa", "Chelsea", "Crystal Palace", "Everton", "Leicester City", "Liverpool", "Manchester City", "Manchester United", "Newcastle United", "Norwich City", "Southampton", "Stoke City", "Sunderland", "Swansea City", "Tottenham Hotspur", "Watford", "West Bromwich Albion", "West Ham United"};
    club *clubAdded;
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
    tail = currentClub;
}


void LeagueTable::enterScore(string winner, int winningGoals, string loser, int losingGoals){
    club *temp = head;
    club *temp2 = head;
    if(winningGoals < losingGoals)
    {
        cout << "Invalid Input" << endl;
    }else
    {
        while(temp != NULL)
        {
            if(temp->name == winner)
            {
                break;
            }
            temp = temp->next;
        }
        while(temp2 != NULL)
        {
            if(temp2->name == loser)
            {
                break;
            }
            temp2 = temp2->next;
        }
        temp->GP = (temp->GP + 1); //both increase games played regardless of outcome
        temp2->GP = (temp2->GP +1);
        if(winningGoals == losingGoals) //tie - each team gets 1 pt
        {
            temp->points = (temp->points + 1);
            temp2->points = (temp2->points + 1);
        }else //winning team gets three points
        {
            temp->points = (temp->points + 3);
        }
    }
}

void LeagueTable::printPointsTable(){
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

void LeagueTable::printGPTable(){
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

void LeagueTable::printAllTable(){
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

void LeagueTable::printStandings(){
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
