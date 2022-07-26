#include <iostream>
#include <fstream>
#include <string>

// Includes header file that I created for different practice functions
#include "practiceFuncs.hpp"


int main(int argc, char *argv[]){
     std::string fileName;

     std::cout << "Name of file to be alphabetically sorted.\n";
     std::cin >> fileName;
     std::ofstream test("..\\" + fileName + ".txt", std::ios::app);

     // Check header file for more information on this function
     jord::sortAlphabet(fileName);

     return 0;
}
