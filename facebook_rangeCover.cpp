#include <iostream>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<pair<int, int> > &pairVec) {
    for (int i = 0; i < pairVec.size(); i++) {
        os << "(" << pairVec[i].first << ", " << pairVec[i].second << ") ";
    }
    return os;
}

vector<pair<int, int> >
findCover(vector<pair<int, int> > &ranges, pair<int, int> queryRange) {
    vector<pair<int, int> > res;
    if (ranges.empty()) return res;

    if (queryRange.first == queryRange.second) {
        for (int i = 0; i<ranges.size(); i++) {
            if (ranges[i].first <= queryRange.first || ranges[i].second >= queryRange.second) {
                res.push_back(ranges[i]);
                return res;
            }
        } 
        return res;
    }
    
    sort(ranges.begin(), ranges.end(), 
         [](const pair<int, int> &a, const pair<int, int> &b){
             return a.first < b.first;
         });

    cout << ranges << endl;

    int target = queryRange.first;
    int maxIndex = 0;
    bool match = false;
    int i = 0;
    while (target < queryRange.second) {
        match = false;
        int maxTarget = target;
        for (i = maxIndex; i < ranges.size(); i++) {
            if (ranges[i].first <= target && ranges[i].second >= maxTarget) {
                maxTarget = ranges[i].second;
                maxIndex = i;
                match = true;
            } else if (ranges[i].first > target) {
                break;
            }
        }
        
        if (!match) {
            return vector<pair<int, int> >();
        }

        res.push_back(ranges[maxIndex]);
        cout << res << endl;
        target = maxTarget;
        maxIndex++;
    }

    return res;
}

int main() {
    vector<pair<int ,int> > test1 = {{1,4}, {30,40}, {20,91}, {8,10}, {6,7}, {3,9}, {9,12}, {11,14}};
    cout << findCover(test1, make_pair(3, 13)) << endl;

    cout << endl;
    vector<pair<int, int> > test2 = {{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {7,8}, {8,9}, {9,10}, {10,11}};
    cout << findCover(test2, make_pair(1, 11))<< endl;
}
