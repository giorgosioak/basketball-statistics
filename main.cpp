#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Player
{
  public:
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

Player player[15] = {};
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

        if (statistic == "show"){
            final_print();
        } else if (statistic == "NAME") {
            getline(iss, team_name);
        } else {
            iss >> player_id;
            do_work(statistic,player_id-1);
        }
    }
   return 0;

}

void do_work(string input, int pid){
    
    if ( input == "FT" ){
        player[pid].FTM++;
        player[pid].FTA++;
        total.FTM++;
        total.FTA++;
        score++;

    } else if ( input == "AFT" ){
        player[pid].FTA++;
        total.FTA++;

    } else if  ( input == "2P" ){
        player[pid].M2P++;
        player[pid].A2P++;
        total.M2P++;
        total.A2P++;
        score+=2;

    } else if  ( input == "A2P" ){
        player[pid].A2P++;
        total.A2P++;

    } else if  ( input == "3P" ){
        player[pid].M3P++;
        player[pid].A3P++;
        total.M3P++;
        total.A3P++;
        score+=3;

    } else if  ( input == "A3P" ){
        player[pid].A3P++;
        total.A3P++;

    } else if  ( input == "DR" ){
        player[pid].DR++;
        total.DR++;

    } else if  ( input == "OR" ){
        player[pid].OR++;
        total.OR++;

    } else if  ( input == "PF" ){
        player[pid].PF++;
        total.PF++;

    } else if  ( input == "ON" ){
        player[pid].ON++;
        total.ON++;
        
    }

}

void final_print(){
    
    cout << "\tFTM\tFTA\t|\tM2P\tA2P\t|\tM3P\tA3P\t|\tDR\tOR\t|\tPF\tON" << endl;
    
    for(int i=3;i<15;i++){
        cout << i+1
            << "\t" << player[i].FTM
            << "\t" << player[i].FTA
            << "\t|\t" << player[i].M2P
            << "\t" << player[i].A2P
            << "\t|\t" << player[i].M3P
            << "\t" << player[i].A3P
            << "\t|\t" << player[i].DR
            << "\t" << player[i].OR
            << "\t|\t" << player[i].PF
            << "\t" << player[i].ON
            << "\t" << i+1 << endl;
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

void set_team_name(string input){

}