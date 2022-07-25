// Header that includes different functions to be used throughout C++ files
#pragma once
#include <string>

namespace func{
    int sortAlphabet(std::string fileName){ 
        int lineCount = 0;
        int ix = 0;

        std::string temp;
        std::ifstream inputStrings;
        inputStrings.open(fileName + ".txt");
        std::ofstream outputStrings;
        outputStrings.open(fileName + "_output.txt");

        while(getline(inputStrings, temp)){
            ++lineCount;
        }
        std::string strArray[lineCount];
        inputStrings.clear();
        inputStrings.seekg(0);

        while(getline(inputStrings, temp)){
            strArray[ix] = temp;
            std::cout << strArray[ix] << "\n";
            ix++;
        }
        for(int x = 0; x < lineCount; x++){
            for(int y = 0; y < strArray[x].size(); y++){

            }
        }

        return 0;
    }
}