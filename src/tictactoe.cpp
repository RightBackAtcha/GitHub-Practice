#include <iostream>
#include <string>

using namespace std;

void gameResponse(char *spaces, int, int);

int main(){ // Simple game of tic-tac-toe made using C++
    int playerInput = 0, aiInput = 0;
    string player1, player2;
    int temp;
    char spaces[9];
    int turns = 0;

    cout << "[1] Singleplayer\n[2] Multiplayer\n";
    cin >> temp;
    if(temp == 1){
        cout << "Player Name...(X)";
        cin >> player1;
        while(turns <= 9 || ());
    }
    else if(temp == 2){
        cout << "Player 1 Name... (X)";
        cin >> player1;
        cout << "Player 2 Name... (O)";
        cin >> player2;
    }

    return 0;
}

void gameResponse(char spaces[], int playerInput, int aiInput){
    cout << "   |   |   \n ";
    cout << spaces[0]; cout << " | "; cout << spaces[1]; cout << " | "; cout << spaces[2];
    cout << " \n   |   |   \n";
    cout << "---------\n";
    cout << "   |   |   \n "; 
    cout << spaces[3]; cout << " | "; cout << spaces[4]; cout << " | "; cout << spaces[5];
    cout << "\n   |   |   \n "; 
    cout << "---------\n";
    cout << "   |   |   \n "; 
    cout << spaces[6]; cout << " | "; cout << spaces[7]; cout << " | "; cout << spaces[8];
    cout << "\n   |   |   \n"; 
}