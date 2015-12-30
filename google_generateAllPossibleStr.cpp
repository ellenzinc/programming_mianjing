#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<string> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << endl;
    }
    return os;
}

void helper(string &s, int pos, vector<string> &res, string cur) {
    int i = pos;
    for (; i < s.length(); i++) {
        if (s[i] == '*') {
            helper(s, i+1, res, cur+'j');
            helper(s, i+1, res, cur+'k');
            break;
        } else {
            cur += s[i];
        }
    }
    if (i == s.length())
        res.push_back(cur);
}

vector<string> allPossibilities(string &s) {
    vector<string> res;
    helper(s, 0, res, "");
    return res;
} 

int main() {
    string test = "*1ab**d*g";
    cout << allPossibilities(test) << endl;
    return 0;
}
