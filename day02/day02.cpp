/** @file day02.cpp
 * @brief Create this file for solve the second exercise of Advento 2022 (https://adventofcode.com/2022/day/2)
 *
 * @author Ana Miranda
 * @date 18/09/2023
*/

#include <iostream>
#include <fstream>
#include <map>

void totalScore(std::ifstream& myfile) {

    std::map<char,int> guideMap;
    guideMap['A'] = 1;
    guideMap['B'] = 2;
    guideMap['C'] = 3;
    guideMap['X'] = 1;
    guideMap['Y'] = 2;
    guideMap['Z'] = 3;

    std::string line = "";
    int score_part1{0}, score_part2{0};
    while(std::getline(myfile, line)) {
        /****************************  Part 1 ****************************/
        // draw
        if (guideMap[line[0]] == guideMap[line[2]]) 
            score_part1 += 3;
        // win
        if (line[0] == 'A' && line[2] == 'Y' || line[0] == 'B' && line[2] == 'Z' || line[0] == 'C' && line[2] == 'X')
            score_part1 += 6;
        
        score_part1 += guideMap[line[2]];

        /****************************  Part 2 ****************************/
        if (line[2] == 'Y') 
            score_part2 += guideMap[line[0]] + 3;      
        else if (line[2] == 'Z') {
            if (line[0] == 'A') 
                score_part2 +=  guideMap['Y'] + 6; 
            if (line[0] == 'B') 
                score_part2 += guideMap['Z'] + 6;
            if (line[0] == 'C')
                score_part2 += guideMap['X'] + 6;
        }
        else  if (line[2] == 'X') {
            if (line[0] == 'A') 
                score_part2 +=  guideMap['Z']; 
            else if (line[0] == 'B') 
                score_part2 += guideMap['X'];
            else if (line[0] == 'C')
                score_part2 += guideMap['Y'];
        }
    }

    std::cout << "Total Score of (Part 1): " << score_part1 << std::endl;
    std::cout << "Total Score of (Part 2): " << score_part2 << std::endl;
}

void readFile(std::string filename) {
    // atach an input stream to the wanted file
    std::ifstream inputStream(filename);

    // check stream status
    if (!inputStream) std::cerr << "Can't open input file!";

    totalScore(inputStream);
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