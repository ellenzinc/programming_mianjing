#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <climits>
#include <limits>
#include <cstddef>

using namespace std;

ostream &operator<< (ostream &os, const vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++)
        os << vec[i] << " ";
    return os;
}

ostream &operator<< (ostream &os, const vector<pair<int, int> > &pairs) {
    for (int i = 0; i < pairs.size(); i++)
        os << "(" << pairs[i].first << ", " << pairs[i].second << ")" << " ";
    return os;
}

ostream &operator<< (ostream &os, const deque<pair<int, double> > &dq) {
    for (int i = 0; i < dq.size(); i++)
        os << dq[i].first << ": " << dq[i].second << endl;
    return os;
} 

double findBound(const pair<int, int> &p1, const pair<int, int> &p2) {
    // assume that p1.first < p2.first;
    double numerator = (double) p2.first * p2.first  - p1.first * p1.first +
        p2.second * p2.second - p1.second * p1.second;
    return 0.5 * numerator / (p2.first - p1.first);
}

vector<pair<int, int> > 
findClosestPoints(vector<int> &consumers, vector< pair<int, int> > &producers) 
{
    vector<pair<int, int> > res;
    deque<pair<int, double> > dq;
    int n = producers.size();
    if (n == 1) {
        res = vector<pair<int, int> >(consumers.size(), producers[0]);
        return res;
    }

    int i = 0, besti = 0;
    int yMin = producers[i++].second;
    while (i < n &&  producers[i] == producers[i-1]) {
        if (producers[i].second < yMin) {
            besti = i;
            yMin = producers[i].second;
        }
        i++;
    }
    dq.push_back(make_pair(besti, numeric_limits<double>::lowest()));

    while (i < n) {
        besti = i;
        yMin = producers[i++].second;
        while (i < n && producers[i] == producers[i-1]) {
            if (producers[i].second < yMin) {
                besti = i;
                yMin = producers[i].second;
            }
            i++;
        }

        double curBound = findBound(producers[dq.back().first], producers[besti]);
        while (curBound < dq.back().second) {
            dq.pop_back();
            curBound = findBound(producers[dq.back().first], producers[besti]);
        }
        dq.emplace_back(besti, curBound);
    }
    cout << dq << endl;

    int idx = 0, dqSize = dq.size();
    for (int v : consumers) {
        while (idx != dqSize-1 && v >= dq[idx+1].second)
            idx++;
        res.push_back(producers[dq[idx].first]);
    }
    return res;
}

int main() {
    vector<int> consumers = {1,5,7};
    vector<pair<int, int> > producers = {{0,3}, {1,1}, {3,2}, {3,1}, {8,10}, {9,100}};
    cout << findClosestPoints(consumers, producers) << endl;

    consumers = {5,7,8};
    producers = {{1,7}, {3,5}, {9,1}};
    cout << findClosestPoints(consumers, producers) << endl;
}
