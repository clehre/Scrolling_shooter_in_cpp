//
// Created by 1024 on 24/04/2022.
//

#include <fstream>
#include <iostream>
#include "FileReader.h"


std::vector<std::string> FileReader::readLines(const char *path) {
    std::string tmp;
    std::vector<std::string> tmpvector;
    std::ifstream file;
    file.open(path, std::ios::in);
    while (std::getline(file, tmp)) {
        tmpvector.emplace_back(tmp);
    }
    file.close();
    return tmpvector;
}

void FileReader::addHighscore(int score) {
    u_long hslength;
    std::vector<std::string> tmp = FileReader::readLines("../csv/hs.csv");
    std::vector<int> tmpArray;

    for (const auto &s: tmp) {
        tmpArray.emplace_back(std::stoi(s));
    }
    tmpArray.emplace_back(score);
    std::sort(tmpArray.begin(), tmpArray.end(), std::greater<>());
    std::fstream file;
    file.open("../csv/hs.csv");
    if (tmpArray.size() > 10) {
        hslength = 10;
    } else {
        hslength = tmpArray.size();
    }
    for (int i = 0; i < hslength; i++) {
        if (i == 9) {
            if (tmpArray.at(i))file << tmpArray.at(i);
            else
                file << "0";
            break;
        }
        if (tmpArray.at(i)) file << tmpArray.at(i) << '\n';
        else
            file << "0\n";
    }
    file.close();
}
