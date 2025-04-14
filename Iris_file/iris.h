//
// Created by bhattacharya on 4/7/2025.
//

#ifndef IRIS_H
#define IRIS_H
#include <vector>
#include <string>
// use structure to store the features and sub-species of each iris flower

struct Iris {
    double features[4];
    std::string species;
};

std::vector<Iris> readCSV(const std::string &filename);




#endif //IRIS_H
