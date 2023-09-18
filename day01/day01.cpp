/** @file adventoOne.cpp
 * @brief Create this file for solve the first exercise of Advento 2022 (https://adventofcode.com/2022/day/1)
 *
 * @author Ana Miranda
 * @date 07/12/2022
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>  
#include <iterator>  
#include <functional>

int part2(std::vector<int>& vecCaloriesElfes) {
    std::sort(vecCaloriesElfes.begin(), vecCaloriesElfes.end(), [] (int a, int b) {return a > b;});
    int caloriesTopThree{0};

    for (int i = 0; i < 3; i++) {
        caloriesTopThree += vecCaloriesElfes[i];
    }
    return caloriesTopThree;
}

int readFilePart1(std::string file_name, std::vector<int>& vecCaloriesElfes) {
    // attach an input stream to the wanted file
    std::ifstream input_stream(file_name);

    // check stream status
    if (!input_stream) std::cerr << "Can't open input file!";

    std::string line;
    int elfCarry{0};;
    while (std::getline(input_stream, line))
    {
        if (line.size() > 1) {
            elfCarry += std::stoi(line);
        }
        else {
            vecCaloriesElfes.push_back(elfCarry);
            elfCarry = 0;
        }
    }

    return *std::max_element(vecCaloriesElfes.begin(), vecCaloriesElfes.end());
}

int main(int argc, char** argv) {
    // create a vector for the elfes calories
    std::vector<int> vecCaloriesElfes;
    if (argc >= 2)
        std::cout << "Elf max calories (Part 1): " << readFilePart1(argv[1], vecCaloriesElfes) << std::endl;
    else
        std::cout << "Puzzle input is missing. Please introduce." << std::endl;
    
    std::cout << "Total of top three calories (Part 2): " << part2(vecCaloriesElfes) << std::endl;

    return 0;
}
