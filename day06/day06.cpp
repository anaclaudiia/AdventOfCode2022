/**
 * @brief Create this file for solve the sixth exercise of Advento 2022 (https://adventofcode.com/2022/day/6)
 * @name  --- Day 6: Tuning Trouble ---
 * @author Ana Miranda
 * @date 04/10/2023
 */

#include <iostream>
#include <string>
#include <fstream>
#include <set>

int Part1(std::string& dataStream, size_t marker) {
    for (int i = 0; i < dataStream.size(); i++) {
        std::string itemMarker = dataStream.substr(i, marker);

        // std::set doesn't take multiple same values it only accepts a unique value.
        std::set<char> itemOrder;
        for (const auto i : itemMarker) {
            itemOrder.insert(i);
        }

        // if this condition is true = all the values are unique
        if (itemOrder.size() == marker) {
            return i + marker;
        }
    }

    return -1;
}

void readFile(std::string filename, std::string& dataStream) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    while(getline(inputStream, dataStream));
}


int main(int argc, char** argv) {
    std::string dataStream;
    if (argc >=2) {
        readFile(argv[1], dataStream);
    }

    const size_t packetMarker{4};
    std::cout << "(Part 1): Is need " << Part1(dataStream, packetMarker) << " characters to be processed" << std::endl;
    const size_t messageMarker{14};
    std::cout << "(Part 2): Is need " << Part1(dataStream, messageMarker) << " characters to be processed" << std::endl;

    return 0;
}