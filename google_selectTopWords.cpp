#include <iostream>
#include <vector>
#include <string>

using namespace std;

using Entry = pair<string, int>;

ostream &operator<<(ostream &os, const vector<Entry> &input) {
    for (int i = 0; i < input.size(); i++) {
        os << input[i].first << ": " << input[i].second << endl;
    }
    return os;
}

void findTopValues(int start, int end, int &mid, int cons, vector<Entry> &input) {
    // make sure larger input are to the left
    if (start > end)
        return;

    if (start == end) {
        if (input[start].second >= cons)
            mid = start+1;
        return;
    }

    int pivot = input[end].second;
    int cur = start;
    int sum = 0;
    for (int i = start; i < end; i++) {
        if (input[i].second > pivot) {
            sum += input[i].second;
            swap(input[i], input[cur++]);
        }
    }
    swap(input[end], input[cur]);
    if (sum == cons) {
        mid = cur;
    } else if (sum > cons) {
        mid = cur;
        findTopValues(start, cur-1, mid, cons, input);
    } else {
        findTopValues(cur, end, mid, cons-sum, input);
    }
}

vector<Entry> topKWithConstraints(vector<Entry> &input, int cons) {
    vector<Entry> res;
    int mid;
    findTopValues(0, input.size()-1, mid, cons, input);
    res.insert(res.end(), input.begin(), input.begin()+mid);
    return res;
} 

int main() {
    vector<Entry> input = {{"B", 300}, {"C", 200}, {"A", 500}, {"D", 100}};
    cout << topKWithConstraints(input, 1200) << endl;
    return 0;
}
