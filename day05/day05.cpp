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
    std::string lineCrates = "";

    std::vector<std::deque<char>> vecCrates;
    int count, from, to {0};
    int index = 0;

    for (size_t i = 0; i < 10; i++) {
        std::deque<char> a;
        vecCrates.push_back(a);
    }

    while(getline(inputStream, lineCrates) && lineCrates[1] != '1') {
        for (size_t i = 1; i < lineCrates.size(); i += 4) {
            vecCrates.at(index).push_back(lineCrates[i]);
            index++;
        }
        index = 0;
    }

    while(getline(inputStream, lineCrates) && lineCrates[0] == 'm') {
        sscanf(lineCrates.c_str(), "move %d from %d to %d", &count, &from, &to);

        for (size_t j = 0; j < count; j++) {
           // vecCrates.at(to).push_back(vecCrates.at(from).pop_back());
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