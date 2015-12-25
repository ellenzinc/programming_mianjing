#include <iostream>
#include <random>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int partition(vector<int> &vec, int start, int end) {
    int pivot = vec[end];
    int cur = start;
    for (int i = start; i < end; i++) {
        if (vec[i] < pivot) {
            swap(vec[i], vec[cur++]);
        }
    }
    swap(vec[cur], vec[end]);
    return cur;
}

// write your own split function
int findKthElement(vector<int> &vec, int start, int mid, int end) {
    if (start == end) {
        return vec[start];
    }
    random_device rd;
    default_random_engine e1(rd());
    uniform_int_distribution<int> uniform_dist(start, end);
    int pivotIdx = uniform_dist(e1);
    swap(vec[pivotIdx], vec[end]);
    pivotIdx = partition(vec, start, end);
    if (pivotIdx == mid) {
        return vec[mid];
    } else if (pivotIdx < mid) {
        return findKthElement(vec, pivotIdx+1, mid, end);
    } else {
        return findKthElement(vec, start, mid, pivotIdx-1);
    }
}

bool isSymmetry(vector<pair<int, int> > &points) {
    int n = points.size();
    vector<int> xVals(n, 0);
    unordered_map<int, unordered_set<int> > xtoy;
    for (int i = 0; i < n; i++) {
        xVals[i] = points[i].first;
        xtoy[points[i].first].insert(points[i].second);
    }
    
    double median;
    if (n % 2) {
        //nth_element(xVals.begin(), xVals.begin() + n/2, xVals.end());
        //median = xVals[n/2];
        median = findKthElement(xVals, 0, n/2, n-1);
    } else {
        //        nth_element(xVals.begin(), xVals.begin() + n/2 - 1, xVals.end());
        median = findKthElement(xVals, 0, n/2-1, n-1) / 2.0 + 
            findKthElement(xVals, n/2, n/2, n-1) / 2.0;

        //nth_element(xVals.begin() + n/2, xVals.begin()+n/2, xVals.end());
        // median = median / 2.0 + xVals[n/2] / 2.0;
    }
    
    cout << "median of x is " << median << endl;
    
    // judge whether it is symmetric
    for (auto p : points) {
        if (p.first <= median) {
            int point2 = (int)(median * 2) - p.first; 
            if (xtoy.count(point2) == 0 || xtoy[point2].count(p.second) == 0)
                return false;
        }
    }
    return true;
}

int main() {
    vector<pair<int, int> > test1 = {{-1,3}, {3,3}, {2,2}, {0,2}};
    cout << isSymmetry(test1) << endl;
    return 0;
}
