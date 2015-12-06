#include <iostream>
#include <vector>

using namespace std;

bool findContinuous(const vector<int> &pos, int K) {
    if (pos.empty()) return false;
    int start = 0;
    int sum = pos[start];
    int i = 1;
    while (i < pos.size()) {
        if (sum == K) 
            return true;
        else if (sum > K) {
            sum -= pos[start];
            start++;
        } else {
            sum += pos[i++];
        }
    }
    return false;
}

int main() {
    cout << findContinuous({1,23,5,4,6,7,34,5}, 22) << endl;
    return 0;
}
