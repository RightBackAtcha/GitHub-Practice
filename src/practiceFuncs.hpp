// Header that includes different functions to be used throughout C++ files
#pragma once
#include <string>
#include <vector>
#include <windows.h>

namespace jord{
    // Function that sorts txt files alphabetically (sorts only by first letter of string currently)
    int sortAlphabet(std::string fileName){  
        int lineCount = 0;
        int ix = 0;

        std::string temp;
        std::string exitPath = ("..\\" + fileName + "_output.txt");
        std::ifstream inputStrings;
        inputStrings.open("..\\" + fileName + ".txt", std::ios::app);
        std::ofstream outputStrings;
        outputStrings.open("..\\" + fileName + "_output.txt");

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
}