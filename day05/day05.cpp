/**
 * @brief Create this file for solve the fifth exercise of Advento 2022 (https://adventofcode.com/2022/day/5)
 * @name  --- Day 5: Supply Stacks ---
 * @author Ana Miranda
 * @date 22/09/2023
 */

#include <iostream>
#include <fstream>

void readFile(std::string filename) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";
    std::string crates;
    while(getline(inputStream, crates)) {

    }
}


int main(int argc, char** argv) {
    if (argc >= 2) {
        readFile(argv[1]);
    }
    else {
        std::cout << "Puzzle input is missing. Please introduce." << std::endl;
    }

    return 0;
}