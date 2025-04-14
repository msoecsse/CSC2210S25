// decision tree algorithm
// Created by bhattacharya on 4/7/2025.
//

#include "id3.h"
#include <map>;
#include <cmath>;
using namespace  std;

double entropy(const std::vector<Iris> &data) {
   map<string, int> counts;
   for(auto &d: data)
      counts[d.species]++;

double ent =0.0;
    for (auto &[species, count]: counts) {
        double p = (double)count/ data.size();
        ent -=p*log2(p);
    }
    return  ent;

}

void buildTree(const std::vector<Iris> &data, std::ostream &os) {
    if(entropy(data)==0) {
        os<< "Leaf" <<data[0].species<<endl;
        return;
    }

int bestFeature = -1;
double bestThreshold = 0, bestGain = 0;

    for (int f=0; f<4; ++f) {
        for(auto &d: data) {
            double threshold =d.feature[f];
            vector<Iris> left, right;
            for (auto &dd: data) {
                if(dd.feature[f]<= threshold) {
                    left.push_back(dd);
                }
                else {
                    right.push_back(dd);
                }
                double gain = entropy(data)- (left.size()*entropy(left)
                    +right.size()*entropy(right))/data.size();

                if(gain >bestGain) {
                    bestGain =gain;
                    bestFeature= f;
                    bestThreshold=threshold;
                }

            }
        }
        if (bestFeature == -1) {
            os << "Leaf (ambiguous): " << data[0].species << endl;
            return;
        }

        os << "Feature " << bestFeature << " <= " << bestThreshold << "?" << endl;

        vector<Iris> left, right;
        for (auto& d : data)
            if (d.features[bestFeature] <= bestThreshold)
                left.push_back(d);
            else
                right.push_back(d);

        os << "Yes branch:" << endl;
        buildTree(left, os);

        os << "No branch:" << endl;
        buildTree(right, os);
    }



    }


}


