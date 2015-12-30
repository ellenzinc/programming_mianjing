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

vector<string> splitString(const string &s) {
    vector<string> res;
    int start = 0;
    bool inquote = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (!inquote) {
                if (i-start > 0)
                    res.push_back(s.substr(start, i-start));
                start = i+1;
            }
        } else if (s[i] == '\"'){
            if (inquote) {
                if (i-start> 0) 
                    res.push_back(s.substr(start, i-start));
            }
            start = i+1;
            inquote = !inquote;
        }
    }
    return res;
}

int main() {
    string test = "This is \"an example\"";
    cout << test << endl;
    cout << splitString(test) << endl;
    return 0;
}
