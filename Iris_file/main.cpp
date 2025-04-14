#include "iris.h"
#include "id3.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <sstream>

using namespace std;

// Helper function to classify using the printed decision tree
string classifyFromTree(istream& is, const Iris& query) {
    string line;
    while (getline(is, line)) {
        if (line.rfind("Feature", 0) == 0) {
            int featureIndex;
            double threshold;
            sscanf(line.c_str(), "Feature %d <= %lf?", &featureIndex, &threshold);

            // Read the next line: should be "Yes branch:"
            getline(is, line);
            streampos yesPos = is.tellg();

            if (query.features[featureIndex] <= threshold) {
                // Go into the Yes branch
                is.seekg(yesPos);
            } else {
                // Skip Yes branch and go to No branch
                int depth = 0;
                while (getline(is, line)) {
                    if (line.rfind("Feature", 0) == 0) depth++;
                    else if (line == "Yes branch:" || line == "No branch:") {
                        if (depth == 0 && line == "No branch:") break;
                        else if (line == "No branch:") depth--;
                    }
                }
            }
        } else if (line.rfind("Leaf", 0) == 0) {
            return line.substr(line.find(":") + 2); // species name
        }
    }
    return "Unknown";
}

int main() {
    // Load dataset and build decision tree
    vector<Iris> dataset = readCSV("iris.csv");

    ofstream treeFile("decision_tree.txt");
    buildTree(dataset, treeFile);
    treeFile.close();

    // Query input from user
    cout << "Enter sepal length, sepal width, petal length, petal width: ";
    Iris query;
    for (int i = 0; i < 4; ++i)
        cin >> query.features[i];

    // Display decision tree
    ifstream treeFileRead("decision_tree.txt");
    string line;
    cout << "\n--- Decision Tree ---\n";
    while (getline(treeFileRead, line)) {
        cout << line << endl;
    }
    treeFileRead.close();

    // Classify input
    ifstream classifyStream("decision_tree.txt");
    string predicted = classifyFromTree(classifyStream, query);
    classifyStream.close();

    cout << "\nPredicted species: " << predicted << endl;

    return 0;
}
