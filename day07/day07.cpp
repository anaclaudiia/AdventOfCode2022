/**
 * @brief Create this file for solve the seventh exercise of Advento 2022 (https://adventofcode.com/2022/day/7)
 * @name  --- Day 7: No Space Left On Device ---
 * @author Ana Miranda
 * @date 07/10/2023
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Part1(std::vector<std::string>& vecData) {
    size_t start = 0, end = 2;
    size_t count{0};
    std:: vector<std::string> directoryName;
    std::string name;
    for (auto i: vecData) {
        std::string word = i.substr(start, end);
        if (word == "di") {
            count ++;
            name = i.substr(end+1);
        }

        if (word == "cd") {
            if (word == "ls") {

            }
        }



    }

}

void readFile(std::string filename, std::vector<std::string>& vecData) {
     // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    std::string dataLine;
    while(getline(inputStream, dataLine)) {
        vecData.push_back(dataLine);
    }
}

int main(int argc, char** argv) {

    std::vector<std::string> vecData;
    if (argc >=2) {
        readFile(argv[1], vecData);
    }

    Part1(vecData);

    return 0;
}