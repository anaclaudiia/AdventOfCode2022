/**
 * @brief Create this file for solve the fourth exercise of Advento 2022 (https://adventofcode.com/2022/day/4)
 * @name  --- Day 4: Camp Cleanup ---
 * @author Ana Miranda
 * @date 21/09/2023
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int part1 (std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>>& pairSection) {
    int numPairs{0};

    // we could also used count_if
    for (auto i : pairSection) {
    if (i.first.first <= i.second.first && i.first.second >= i.second.second ||
        i.second.first <= i.first.first && i.second.second >= i.first.second) 
        numPairs ++;
    }

    return numPairs;
}

int part2(std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>>& pairSection) {
    int numOverleap{0};

    // we could also used count_if
    for (auto i : pairSection) {
        if (i.first.first <= i.second.second && i.second.first <= i.first.second)
            numOverleap ++;
    }

   return numOverleap;
}

void readFile(std::string filename, std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>>& pairSection) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    std::string listSection;
    int part1_1,part1_2, part2_1, part2_2;
    int numPairs{0};
    while(getline(inputStream, listSection)) {
        sscanf(listSection.c_str(), "%d-%d,%d-%d", &part1_1, &part1_2, &part2_1, &part2_2);
        pairSection.push_back(std::make_pair(std::make_pair(part1_1, part1_2), 
                             std::make_pair(part2_1, part2_2)));
    }
}

int main(int argc, char**argv) {
    std::vector<std::pair<std::pair<int,int>,std::pair<int,int>>> pairSection;
    if(argc >=2 ) {
        readFile(argv[1], pairSection);
    }
    else {
        std::cout << "Puzzle input is missing. Please introduce." << std::endl;
    }

    std::cout << "Number of pairs that one range fully contain the other (Part 1): " << part1(pairSection) << std::endl;
    std::cout << "Number of overleap (Part 2): " << part2(pairSection) << std::endl;
}