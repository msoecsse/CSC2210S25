#ifndef IRIS_H
#define IRIS_H

#include <vector>
#include <string>
// this structure is used to store the features and species of each iris flower
struct Iris {
    double features[4];
    std::string species;
};
//qthis function reads a CSV file
//and returns a vector of Iris structures
std::vector<Iris> readCSV(const std::string& filename);

#endif // IRIS_H
