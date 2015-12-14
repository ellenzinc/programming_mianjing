#include <iostream>
#include <iomanip>
#include <random>
#include <cmath>
#include <map>

using namespace std;

int generateRandomNumber(const vector<double> &prob, const vector<int> &vals) {
    random_device rd;
    default_random_engine e1(rd());
    uniform_real_distribution<> uniform_dist(0, 1);
    double value = uniform_dist(e1);

    for (int i = 0; i < prob.size(); i++)
        if (value <= prob[i])
            return vals[i];
}

int main() {
    vector<double> prob = {0.1, 0.3, 0.25, 0.35};
    vector<int> vals = {1,2,3,4};
    map<int, double> hist;
    for (int i = 1; i <prob.size(); i++)
        prob[i] += prob[i-1];

    for (int n = 0; n < 10000; n++) {
        int a = generateRandomNumber(prob, vals);
        hist[a] = hist[a] + 1;
    }

    for (auto it = hist.begin(); it != hist.end(); it++) {
        it->second /= 10000.0;
        cout <<it->first << " probability " << it->second << " "; 
    }
    cout << endl;
}
