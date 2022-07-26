#include <iostream>
#include <fstream>
#include <string>

// Includes header file that I created
#include "practiceFuncs.hpp"


int main(){
     std::string fileName = "test";
     std::ofstream test("..\\" + fileName + ".txt", std::ios::app);

     func::sortAlphabet(fileName);

}
