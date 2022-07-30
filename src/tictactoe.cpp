#include <iostream>
#include <string>

using namespace std;

void gameResponse(char spaces[]);
bool checkWinner(char spaces[], );

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
        while(turns <= 9 || (checkWinner(spaces) == true) || (checkWinner(spaces) != true)){

        }
    }
    else if(temp == 2){
        cout << "Player 1 Name... (X)";
        cin >> player1;
        cout << "Player 2 Name... (O)";
        cin >> player2;
    }
    if(checkWinner(spaces)){
        cout << "You Win!";
        return 0;
    }
    else if(checkWinner(spaces)){
        cout << "You Lose!";
        return 0;
    }

    return 0;
}

void gameResponse(char spaces[]){
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
bool checkWinner(char spaces[]){
    if(spaces[0] == 'X' && spaces[1] == 'X' && spaces[2] == 'X'){
        return true;
    }
    else if(spaces[0] == 'O' && spaces[1] == 'O' && spaces[2] == 'O'){
        return false;
    }
    else if(spaces[3] == 'X' && spaces[4] == 'X' && spaces[5] == 'X'){
        return true;
    }
    else if(spaces[3] == 'O' && spaces[4] == 'O' && spaces[5] == 'O'){
        return false;
    }
    else if(spaces[6] == 'X' && spaces[7] == 'X' && spaces[8] == 'X'){
        return true;
    }
    else if(spaces[6] == 'O' && spaces[7] == 'O' && spaces[8] == 'O'){
        return false;
    }
    else if(spaces[1] == 'X' && spaces[3] == 'X' && spaces[6] == 'X'){
        return true;
    } 
    else if(spaces[1] == 'O' && spaces[3] == 'O' && spaces[6] == 'O'){
        return false;
    } 
    else if(spaces[1] == 'X' && spaces[4] == 'X' && spaces[7] == 'X'){
        return true;
    }
    else if(spaces[1] == 'O' && spaces[4] == 'O' && spaces[7] == 'O'){
        return false;
    }
    else if(spaces[2] == 'X' && spaces[5] == 'X' && spaces[8] == 'X'){
        return true;
    } 
    else if(spaces[2] == 'O' && spaces[5] == 'O' && spaces[8] == 'O'){
        return false;
    } 
    else if(spaces[0] == 'X' && spaces[4] == 'X' && spaces[8] == 'X'){
        return true;
    }
    else if(spaces[0] == 'O' && spaces[4] == 'O' && spaces[8] == 'O'){
        return false;
    }
    else if(spaces[2] == 'X' && spaces[4] == 'X' && spaces[6] == 'X'){
        return true;
    }
    else if(spaces[2] == 'O' && spaces[4] == 'O' && spaces[6] == 'O'){
        return false;
    }
}