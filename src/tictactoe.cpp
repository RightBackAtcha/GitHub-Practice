#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

// Function that outputs current game state after each turn
void gameResponse(char spaces[]);

// Function that checks whether the player has won or not (outputs 1 for X and -1 for O)
int checkWinner(char spaces[]);

// Function used to generate random AI turn for singleplayer game
void aiInput(char spaces[], default_random_engine);

// Simple game of tic-tac-toe made using C++
int main(){
    int playerInput = 0;
    string player1, player2;
    int temp;
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int turns = 0;

    // Random number generator based on device seed used for AI pick
    random_device rnd;
    default_random_engine ai(rnd());

    // Main loop function for tic tac toe game
    cout << "[1] Singleplayer\n[2] Multiplayer\n";
    cin >> temp;
    if(temp == 1){ // Singleplayer component of main game loop
        cout << "Player Name...(X)\n";
        cin >> player1;
        while(turns < 9 || checkWinner(spaces) == -1){
            this_thread::sleep_for(chrono::milliseconds(1000));            
            cout << "What space would you like to take (1 - 9) " << player1 << "?\n";
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
            playerInput -=1;
            spaces[playerInput] = 'X';
            playerInput = 0;
            turns++;
            gameResponse(spaces);

            // Checks if X has won the game
            if(checkWinner(spaces) == 1){
                cout << "3 in a row! You Win!\n";
                this_thread::sleep_for(chrono::milliseconds(3500));
                return 1;
            }
            this_thread::sleep_for(chrono::milliseconds(1500));          
            aiInput(spaces, ai);
            turns++;
            cout << "\n\n";
            gameResponse(spaces);

            // Checks if O has won the game
            if(checkWinner(spaces) == -1){
                cout << "You Lose...\n";
                this_thread::sleep_for(chrono::milliseconds(3500));                
                return -1;
            }
        }
        cout << "Tie Game!";
        this_thread::sleep_for(chrono::milliseconds(3500));
        return 0;
    }
    else if(temp == 2){ // Multiplayer component of main game loop
        cout << "Player 1 Name... (X)\n";
        cin >> player1;
        cout << "Player 2 Name... (O)\n";
        cin >> player2;
        while(turns < 9){
            cout << "What space would you like to take (1 - 9) " << player1 << "?\n";
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
            playerInput -=1;
            spaces[playerInput] = 'X';
            playerInput = 0;
            turns ++;
            gameResponse(spaces);
            // Checks if Player 1 has won the game
            if(checkWinner(spaces) == 1){
                cout << player1 << "has won the game!";
                this_thread::sleep_for(chrono::milliseconds(3500));
                return 1;
            }

            cout << "What space would you like to take (1 - 9) " << player2 << "?\n";
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
            playerInput -=1;
            spaces[playerInput] = 'O';
            playerInput = 0;
            turns ++;
            gameResponse(spaces);
            // Checks if Player 2 has won the game
            if(checkWinner(spaces) == -1){
                cout << player2 << " has won the game!";
                this_thread::sleep_for(chrono::milliseconds(3500));                
                return -1;
            }
        }
        cout << "Tie Game!";
        this_thread::sleep_for(chrono::milliseconds(3500));
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
int checkWinner(char spaces[]){
    if(spaces[0] == 'X' && spaces[1] == 'X' && spaces[2] == 'X'){
        return 1;
    }
    else if(spaces[0] == 'O' && spaces[1] == 'O' && spaces[2] == 'O'){
        return -1;
    }
    else if(spaces[3] == 'X' && spaces[4] == 'X' && spaces[5] == 'X'){
        return 1;
    }
    else if(spaces[3] == 'O' && spaces[4] == 'O' && spaces[5] == 'O'){
        return -1;
    }
    else if(spaces[6] == 'X' && spaces[7] == 'X' && spaces[8] == 'X'){
        return 1;
    }
    else if(spaces[6] == 'O' && spaces[7] == 'O' && spaces[8] == 'O'){
        return -1;
    }
    else if(spaces[0] == 'X' && spaces[3] == 'X' && spaces[6] == 'X'){
        return 1;
    } 
    else if(spaces[0] == 'O' && spaces[3] == 'O' && spaces[6] == 'O'){
        return -1;
    } 
    else if(spaces[1] == 'X' && spaces[4] == 'X' && spaces[7] == 'X'){
        return 1;
    }
    else if(spaces[1] == 'O' && spaces[4] == 'O' && spaces[7] == 'O'){
        return -1;
    }
    else if(spaces[2] == 'X' && spaces[5] == 'X' && spaces[8] == 'X'){
        return 1;
    } 
    else if(spaces[2] == 'O' && spaces[5] == 'O' && spaces[8] == 'O'){
        return -1;
    } 
    else if(spaces[0] == 'X' && spaces[4] == 'X' && spaces[8] == 'X'){
        return 1;
    }
    else if(spaces[0] == 'O' && spaces[4] == 'O' && spaces[8] == 'O'){
        return -1;
    }
    else if(spaces[2] == 'X' && spaces[4] == 'X' && spaces[6] == 'X'){
        return 1;
    }
    else if(spaces[2] == 'O' && spaces[4] == 'O' && spaces[6] == 'O'){
        return -1;
    }
    return 0;
}
void aiInput(char spaces[], default_random_engine ai){
    uniform_int_distribution<int> gen(0, 8);
    int output = gen(ai);
    while(spaces[output] == 'X' || spaces[output] == 'O'){
        output = gen(ai);
    }
    spaces[output] = 'O';
}