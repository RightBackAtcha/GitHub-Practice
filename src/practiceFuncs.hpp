// Header that includes different functions to be used throughout C++ files
#pragma once
#include <string>
#include <vector>

namespace jord{
    // Function that sorts txt files alphabetically (sorts only by first letter of string)
    int sortAlphabet(std::string fileName){ 
        int lineCount = 0;
        int ix = 0;

        std::string temp;
        std::ifstream inputStrings;
        inputStrings.open("..\\" + fileName + ".txt", std::ios::app);
        std::ofstream outputStrings;
        outputStrings.open("..\\" + fileName + "_output.txt");

        while(getline(inputStrings, temp)){
            ++lineCount;
        }
        std::string strArray[lineCount];
        std::vector<int> strVector(lineCount);
        std::vector<int> usage(lineCount);
        inputStrings.clear();
        inputStrings.seekg(0);

        while(getline(inputStrings, temp)){
            strArray[ix] = temp;
            ix++;
        }
        inputStrings.close();
        for(int x = 0; x < lineCount; x++){ // For loop that checks each first letter and inputs letter position into vector
            if(strArray[x][0] == 'a' || strArray[x][0] == 'A'){
                strVector[x] = 1;
            }
            else if(strArray[x][0] == 'b' || strArray[x][0] == 'B'){
                strVector[x] = 2;
            }
            else if(strArray[x][0] == 'c' || strArray[x][0] == 'C'){
                strVector[x] = 3;
            }
            else if(strArray[x][0] == 'd' || strArray[x][0] == 'D'){
                strVector[x] = 4;
            }
            else if(strArray[x][0] == 'e' || strArray[x][0] == 'E'){
                strVector[x] = 5;
            }
            else if(strArray[x][0] == 'f' || strArray[x][0] == 'F'){
                strVector[x] = 6;
            }
            else if(strArray[x][0] == 'g' || strArray[x][0] == 'G'){
                strVector[x] = 7;
            }
            else if(strArray[x][0] == 'h' || strArray[x][0] == 'H'){
                strVector[x] = 8;
            }
            else if(strArray[x][0] == 'i' || strArray[x][0] == 'I'){
                strVector[x] = 9;
            }
            else if(strArray[x][0] == 'j' || strArray[x][0] == 'J'){
                strVector[x] = 10;
            }
            else if(strArray[x][0] == 'k' || strArray[x][0] == 'K'){
                strVector[x] = 11;
            }
            else if(strArray[x][0] == 'l' || strArray[x][0] == 'L'){
                strVector[x] = 12;
            }
            else if(strArray[x][0] == 'm' || strArray[x][0] == 'M'){
                strVector[x] = 13;
            }
            else if(strArray[x][0] == 'n' || strArray[x][0] == 'N'){
                strVector[x] = 14;
            }
            else if(strArray[x][0] == 'o' || strArray[x][0] == 'O'){
                strVector[x] = 15;
            }
            else if(strArray[x][0] == 'p' || strArray[x][0] == 'P'){
                strVector[x] = 16;
            }
            else if(strArray[x][0] == 'q' || strArray[x][0] == 'Q'){
                strVector[x] = 17;
            }
            else if(strArray[x][0] == 'r' || strArray[x][0] == 'R'){
                strVector[x] = 18;
            }
            else if(strArray[x][0] == 's' || strArray[x][0] == 'S'){
                strVector[x] = 19;
            }
            else if(strArray[x][0] == 't' || strArray[x][0] == 'T'){
                strVector[x] = 20;
            }
            else if(strArray[x][0] == 'u' || strArray[x][0] == 'U'){
                strVector[x] = 21;
            }
            else if(strArray[x][0] == 'v' || strArray[x][0] == 'V'){
                strVector[x] = 22;
            }
            else if(strArray[x][0] == 'w' || strArray[x][0] == 'W'){
                strVector[x] = 23;
            }
            else if(strArray[x][0] == 'x' || strArray[x][0] == 'X'){
                strVector[x] = 24;
            }
            else if(strArray[x][0] == '0' || strArray[x][0] == 'Y'){
                strVector[x] = 25;
            }
            else if(strArray[x][0] == 'z' || strArray[x][0] == 'Z'){
                strVector[x] = 26;
            }
            else{
                std::cout << "Error in program...\nExiting";
                return -1;
            }
        }
        while(usage != strVector){ // While loop that outputs 
            int smallestVal = 26;
            for(int x = 0; x < strVector.size(); x++){
                if((strVector[x] <= smallestVal) && strVector[x] != 0){
                    smallestVal = strVector[x];
                }
            }
            for(int x = 0; x < strVector.size(); x++){  
                if(strVector[x] == smallestVal){
                    outputStrings << strArray[x] << "\n";
                    strVector[x] = 0;
                }
            }
        }
        return 0;
    }
}