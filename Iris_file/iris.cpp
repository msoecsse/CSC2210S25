#include "iris.h"
#include <fstream>
#include <sstream>
using namespace std;
// creates a vector of Iris structures

vector<Iris> readCSV(const string& filename) {
    vector<Iris> data;
    ifstream file(filename);
    string line;
// while loop to read each line of the file
    while (getline(file, line)) {
        //stringstream is used to parse the line
        //it breaks the line into tokens using the comma as a delimiter
        stringstream ss(line); // create a stringstream object
        Iris iris; // create an Iris structure
        char delim; // delimiter for parsing
        // delim is used to read the comma between the features
        // read the first four features
        // the >> operator reads the value and the delim variable is used to discard the comma
        for (int i = 0; i < 4; ++i)
            ss >> iris.features[i] >> delim;// read the feature value and discard the comma
        // read the species name
        // the getline function is used to read the rest of the line

        getline(ss, iris.species); // read the species name
        data.push_back(iris); // add the iris structure to the vector
    }
    return data;
}
// alternatively, you can use the following code to read the CSV file
// vector<Iris> readCSV(const string& filename) {
//     vector<Iris> data;
//     ifstream file(filename);
//     string line;
//
//     if (!file.is_open()) {
//         throw runtime_error("Could not open file: " + filename);
//     }
//
//     while (getline(file, line)) {
//         stringstream ss(line);
//         string token;
//         Iris iris;
//
//         for (int i = 0; i < 4; ++i) {
//             if (!getline(ss, token, ',')) break;
//             iris.features[i] = stof(token); // stof converts string to float
//         }
//
//         if (getline(ss, token)) {
//             iris.species = token;
//             data.push_back(iris);
//         }
//     }
//
//     return data;
// }
