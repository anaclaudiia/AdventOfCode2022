/**
 * @brief Create this file for solve the sixth exercise of Advento 2022 (https://adventofcode.com/2022/day/6)
 * @name  --- Day 6: Tuning Trouble ---
 * @author Ana Miranda
 * @date 04/10/2023
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int Part1(std::string& dataStream) {
    auto position{0};
    std::string::iterator it;

    for (auto i : dataStream) {
        if (((dataStream[i] != dataStream[i+1]) && ((dataStream[i] != dataStream[i+1]) != dataStream[i+2]))
         && (((dataStream[i] != dataStream[i+1]) && ((dataStream[i] != dataStream[i+1]) != dataStream[i+2])) != dataStream[i+3]))
        {
            it = std::find(dataStream.begin(), dataStream.end(), dataStream[i+3]);
        }
    }
        if (it != dataStream.end()) {
            std::cout << it - dataStream.begin();
        }
  
    return position;
}

void readFile(std::string filename, std::string& dataStream) {
    // attach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    while(getline(inputStream, dataStream)) {
    }
}


int main(int argc, char** argv) {
    std::string dataStream;
    if (argc >=2) {
        readFile(argv[1], dataStream);
    }

    std::cout << "(Part 1): Is need " << Part1(dataStream) << " characters to be processed" << std::endl;

    return 0;
}