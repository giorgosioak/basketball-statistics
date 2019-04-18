#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Player
{
  public:
    int id = 0;     // Player ID number (as shown on uniform)
    string full_name = "";  // Player Full Name
    int FTM = 0;    // field goals made
    int FTA = 0;    // field goals attemted
    int M2P = 0;    // field goals made
    int A2P = 0;    // field goals attempted
    int M3P = 0;    // free throws made
    int A3P = 0;    // free throws attempted
    int DR = 0;     // Defensive Rebound
    int OR = 0;     // Offensive Rebound
    int PF = 0;     // Player Foul
    int ON = 0;     // Foul on
};

void do_work(string input, int player_id);
void final_print();

Player player[100] = {};
vector <int> participation;
Player total = Player();
int score = 0;
string team_name = "";

int main () {

    string input;
    while(getline(cin,input))
    {
        string statistic;
        string player_id_s;
        int player_id;

        istringstream iss(input);
        iss >> statistic;

        if ( statistic == "SHOW" || statistic == "show" ){
            final_print();
        } else if ( statistic == "NAME" || statistic == "name" ) {
            getline(iss, team_name);
        } else if ( statistic == "SET" || statistic == "set" ) {
            iss >> player_id;
            player[player_id].id = player_id;   // add id to class Player
            getline(iss, player[player_id].full_name);  // add name to class player
            participation.push_back(player_id); // add to participated
        }
        else {
            iss >> player_id;
            do_work(statistic,player_id);
        }
    }
   return 0;

}

void do_work(string input, int pid){
    
    if ( input == "FT" || input == "ft" ){
        player[pid].FTM++;
        player[pid].FTA++;
        total.FTM++;
        total.FTA++;
        score++;

    } else if ( input == "AFT" || input == "aft" ){
        player[pid].FTA++;
        total.FTA++;

    } else if  ( input == "2P" || input == "2p" ){
        player[pid].M2P++;
        player[pid].A2P++;
        total.M2P++;
        total.A2P++;
        score+=2;

    } else if  ( input == "A2P" || input == "a2p" ){
        player[pid].A2P++;
        total.A2P++;

    } else if  ( input == "3P" || input == "3p" ){
        player[pid].M3P++;
        player[pid].A3P++;
        total.M3P++;
        total.A3P++;
        score+=3;

    } else if  ( input == "A3P" || input == "a3p" ){
        player[pid].A3P++;
        total.A3P++;

    } else if  ( input == "DR" || input == "dr" ){
        player[pid].DR++;
        total.DR++;

    } else if  ( input == "OR" || input == "or" ){
        player[pid].OR++;
        total.OR++;

    } else if  ( input == "PF" || input == "pf" ){
        player[pid].PF++;
        total.PF++;

    } else if  ( input == "ON" || input == "on" ){
        player[pid].ON++;
        total.ON++;
        
    }

}

void final_print(){
    
    cout << "\tFTM\tFTA\t|\tM2P\tA2P\t|\tM3P\tA3P\t|\tDR\tOR\t|\tPF\tON" << endl;
    
    for (int i = 0; i != participation.size(); i++) {
        int pid = participation[i];
        cout << pid
            << "\t" << player[pid].FTM
            << "\t" << player[pid].FTA
            << "\t|\t" << player[pid].M2P
            << "\t" << player[pid].A2P
            << "\t|\t" << player[pid].M3P
            << "\t" << player[pid].A3P
            << "\t|\t" << player[pid].DR
            << "\t" << player[pid].OR
            << "\t|\t" << player[pid].PF
            << "\t" << player[pid].ON
            << "\t" << pid << "\t" << player[pid].full_name << endl;
    }

    cout << "---------------------------------------------------------";
    cout << "---------------------------------------------------------\n";
    
    cout << "TOT"
    << "\t" << total.FTM
    << "\t" << total.FTA
    << "\t|\t" << total.M2P
    << "\t" << total.A2P
    << "\t|\t" << total.M3P
    << "\t" << total.A3P
    << "\t|\t" << total.DR
    << "\t" << total.OR
    << "\t|\t" << total.PF
    << "\t" << total.ON
    << endl;

    cout << "SCORE: " << score << " " << team_name << endl;

}