#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

void gameResponse(char spaces[]);
bool checkWinner(char spaces[]);
void aiInput(char spaces[], default_random_engine);

int main(){ // Simple game of tic-tac-toe made using C++
    int playerInput = 0;
    string player1, player2;
    int temp;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turns = 0;

    // Random number generator based on device seed used for AI pick
    random_device rnd;
    default_random_engine ai(rnd());

    cout << "[1] Singleplayer\n[2] Multiplayer\n";
    cin >> temp;
    if(temp == 1){
        cout << "Player Name...(X)\n";
        cin >> player1;
        while(turns < 9 || checkWinner(spaces) == false){
            cout << "What space would you like to take (1 - 9) " << player1 << "\n";
            while(playerInput == 0){
                cin >> playerInput;
                if(playerInput > 9 || playerInput < 1){
                    cout << "Error! Invalid input.\n";
                    playerInput = 0;
                }
                else if(spaces[playerInput-1] == 'X' || spaces[playerInput-1] == 'O'){
                    cout << "Error! Space is already taken.\n";
                    playerInput = 0;
                }
            }
            playerInput = playerInput - 1;
            spaces[playerInput] = 'X';
            playerInput = 0;
            aiInput(spaces, ai);
            turns++;
            gameResponse(spaces);

            if(checkWinner(spaces)){
                cout << "3 in a row! You win!\n";
                this_thread::sleep_for(chrono::microseconds(3500));
                return 1;
            }
        }
        if(!checkWinner(spaces)){
            cout << "You lose!\n";
            this_thread::sleep_for(chrono::microseconds(3500));
            return -1;
        } else
            cout << "Tie Game!";
            this_thread::sleep_for(chrono::microseconds(3500));
            return 0;
    }
    else if(temp == 2){
        cout << "Player 1 Name... (X)\n";
        cin >> player1;
        cout << "Player 2 Name... (O)\n";
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
    cout << "-----------\n";
    cout << "   |   |   \n "; 
    cout << spaces[3]; cout << " | "; cout << spaces[4]; cout << " | "; cout << spaces[5];
    cout << "\n   |   |   \n"; 
    cout << "-----------\n";
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

    return NULL;
}
void aiInput(char spaces[], default_random_engine ai){
    uniform_int_distribution<int> gen(0, 8);
    int output = gen(ai);
    while(spaces[output] == 'X' || spaces[output] == 'O'){
        output = gen(ai);
    }
    spaces[output] = 'O';
}