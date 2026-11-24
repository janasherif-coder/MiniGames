#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    int player , computer;
    string playername;

    srand(time(0));
    computer = rand() % 3 + 1;

    cout << "Rock Paper Scissor Game!" << endl;
    cout << "Player Name: ";
    cin >> playername;
    cout << "1. Rock\n" << "2. Paper\n" << "3. Scissor\n";
    cout << "Enter your choice(1-3): ";
    cin >> player;

    cout << "Computer choice: " << computer << endl;

    if(player == computer){
        cout << "Draw!" << endl;
    }

    else if((player == 1 && computer == 3) ||
           (player == 2 && computer == 1) || 
           (player == 3 && computer == 2)){
        cout << playername << " wins!" << endl;
    }
    
    else cout << "Computer wins!" << endl;


    return 0;
}