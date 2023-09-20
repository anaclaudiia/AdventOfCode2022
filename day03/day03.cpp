/** @file day03.cpp
 * @brief Create this file for solve the third exercise of Advento 2022 (https://adventofcode.com/2022/day/3)
 *
 * @author Ana Miranda
 * @date 18/09/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int strToNum(int value) {
    if (value - 96 < 0) {
        return value - 38;
    }
    else {
        return value - 96;
    }
}

int part1(std::vector<std::string>& vecRucksacks) {
    int priority{0};

    for (auto line : vecRucksacks) {
        const auto size{line.size() / 2};
        priority += strToNum(*std::find_first_of(line.begin(), line.end() - size, line.end() - size, line.end()));
    }
    return priority;
}

int part2(std::vector<std::string>& vecRucksacks) {
    int priority{0};
    std::string line1, line2, line3;

    for (int i = 0 ; i < vecRucksacks.size(); i += 3) {
        line1 = vecRucksacks[i]; 
        line2 = vecRucksacks[i+1];
        line3 = vecRucksacks[i+2]; 

        for (auto item : line1) {
            if (line2.find(item) != std::string::npos && line3.find(item) != std::string::npos) {
                priority += strToNum(item);
                break;
            }
        }
    }
    return priority;
}

void readFile(std::string filename, std::vector<std::string>& vecRucksacks) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    std::string listContent;
    while(std::getline(inputStream, listContent)) {
        vecRucksacks.push_back(listContent);
    }
}

int main (int argc, char** argv) {
    std::vector<std::string> vecRucksacks;
    if (argc >= 2) {
        readFile(argv[1], vecRucksacks);
    }
    else {
        std::cout << "Puzzle input is missing. Please introduce." << std::endl;
    }

    std::cout << "Sum of the priorities of the items (Part 1): " << part1(vecRucksacks) << std::endl;
    std::cout << "Sum of the priorities of the items (Part 2): " << part2(vecRucksacks) << std::endl;

    return 0;
}
