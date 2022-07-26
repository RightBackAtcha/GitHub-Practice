// Header that includes different functions to be used throughout C++ files
#pragma once
#include <string>
#include <vector>

namespace func{
    int sortAlphabet(std::string fileName){ 
        int lineCount = 0;
        int ix = 0;

        std::string temp;
        std::ifstream inputStrings;
        inputStrings.open("..\\" + fileName + ".txt");
        std::ofstream outputStrings;
        outputStrings.open("..\\" + fileName + "_output.txt");

        while(getline(inputStrings, temp)){
            ++lineCount;
        }
        std::string strArray[lineCount];
        std::vector<int> strVector(lineCount);
        inputStrings.clear();
        inputStrings.seekg(0);

        while(getline(inputStrings, temp)){
            strArray[ix] = temp;
            ix++;
        }
        for(int x = 0; x < lineCount; x++){
            for(int y = 0; y < strArray[x].size(); y++){
                if(strArray[x][y] == 'a' || strArray[x][y] == 'A'){
                    std::cout << strArray[x];
                }
            }
        }

        return 0;
    }
}