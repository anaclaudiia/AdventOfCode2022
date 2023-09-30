/**
 * @brief Create this file for solve the fifth exercise of Advento 2022 (https://adventofcode.com/2022/day/5)
 * @name  --- Day 5: Supply Stacks ---
 * @author Ana Miranda
 * @date 22/09/2023
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

void readFile(std::string filename) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";
    std::string crates = "";

    std::vector<std::deque<char>> stackCrates;
    int count, from, to {0};
    while(getline(inputStream, crates)) {
        sscanf(crates.c_str(), "move %d from %d to %d", &count, &from, &to);

        for (int i = 0; i < count; i++) {
            // here we should move the crates
        }
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