#ifndef ID3_H
#define ID3_H

#include "iris.h"
#include <vector>
#include <ostream>

double entropy(const std::vector<Iris>& data);
void buildTree(const std::vector<Iris>& data, std::ostream& os);

#endif // ID3_H
