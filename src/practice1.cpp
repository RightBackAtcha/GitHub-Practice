#include <iostream>
#include <fstream>
#include <string>

// Includes header file that I created
#include "practiceFuncs.hpp"


int main(){
     std::string fileName;

     std::cout << "Name of file to be alphabetically sorted.\n";
     std::cin >> fileName;
     std::ofstream test("..\\" + fileName + ".txt", std::ios::app);

     jord::sortAlphabet(fileName);

     return 0;
}
