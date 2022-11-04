#include <iostream>
#include <fstream>
#include <string>

// Includes header file that I created for different practice functions
#include "practiceFuncs.hpp"


int main(int argc, char *argv[]){
     int select = 0;
     std::string fileName;
     int maxNum = 0;
     std::cout << "Which function would you like to use?\n[1] Sort txt file\n[2] Random Number Guesser Game\n";
     std::cin >> select;
     if(select == 1){

          std::cout << "\nName of file to be alphabetically sorted.\n";
          std::cin >> fileName;
          std::ofstream inputFile("..\\data\\" + fileName + ".txt", std::ios::app);

          // Check header file for more information on this function
          jord::sortAlphabet(fileName);
     }
     else if(select == 2){
          std::cout << "\nInput a maximum number between 1 and 100...\n";
          while(maxNum == 0 || maxNum > 100){
               std::cin >> maxNum;
               if(maxNum == 0 || maxNum > 100){
                    std::cout << "\nError: Invalid mumber. Please input a new number\n";
               }
          }
          jord::numberGuess(maxNum);
     }
     return 0;
}
