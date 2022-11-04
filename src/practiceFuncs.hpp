// Header that includes different functions to be used throughout C++ files
#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <random>

namespace jord{
    // Function that sorts txt files alphabetically (sorts only by first letter of string currently)
    int sortAlphabet(std::string fileName){  
        int lineCount = 0;
        int ix = 0;

        std::string temp;
        std::string exitPath = ("..\\data\\" + fileName + "_output.txt");
        std::ifstream inputStrings;
        inputStrings.open("..\\data\\" + fileName + ".txt", std::ios::app);
        std::ofstream outputStrings;
        outputStrings.open(exitPath);

        while(getline(inputStrings, temp)){ // Counts total amount of lines found in input file
            ++lineCount;
        } 
        std::string strArray[lineCount];
        inputStrings.clear();
        inputStrings.seekg(0);

        while(getline(inputStrings, temp)){
            for(int ix = 0; ix < temp.length(); ix++){
                temp[ix] = toupper(temp[ix]);
            }
            strArray[ix] = temp;
            ix++;
        }
        inputStrings.close();

        for(int ix = 0; ix < lineCount; ix++){
            temp = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
            for(int x = 0; x < lineCount; x++){
                if(temp > strArray[x] && (strArray[x] != "")){
                    temp = strArray[x];
                }
            }
            for(int x = 0; x < lineCount; x++){
                if(temp == strArray[x]){
                    strArray[x].erase();
                }
            }
            outputStrings << temp << "\n";
        }
        outputStrings.close(); // After execution of function, opens output file
        ShellExecuteA(NULL, "open", exitPath.c_str(), NULL, NULL, 0);
        return 0;
    }
    int numberGuess(int maxNum){
        // Var that stores number of guesses used
        int guessNum = 1;
        int temp;

        // Random generator used for number guesser
        std::random_device rnd;
        std::default_random_engine guess(rnd());
        std::uniform_int_distribution<int> rndm(0, maxNum);

        // Randomly generated number we are trying to find
        int num = rndm(guess);

        std::cout << "I'm thinking of a number from 0 to " << maxNum << ". Do you know what it is?";
        while(maxNum != 3){
            std::cout << "\nGuess a number!\n";
            std::cin >> temp;

            if(temp == num && guessNum == 1){
                std::cout << "Good job! You guessed it on your first guess!";
                return 1;
            }
            else if(temp == num){
                std::cout << "Good job! You guessed it in " << (guessNum) << " guesses!";
                return 1;
            }
            else if(guessNum > 2){
                std::cout << "Tough luck chump. You didn't get it at all...";
                return 0;
            }
            else{
                std::cout << "Wrong! Guess again.";
                guessNum ++;
            }
        }

        return 0;
    }
}