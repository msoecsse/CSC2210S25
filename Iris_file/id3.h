//
// Created by bhattacharya on 4/7/2025.
//

#ifndef ID3_H
#define ID3_H

#include "iris.h"
#include <vector>
#include <ostream>

double entropy(const std::vector<Iris> &data);
void buildTree(const std::vector<Iris> &data, std:: ostream &os);
#endif //ID3_H
