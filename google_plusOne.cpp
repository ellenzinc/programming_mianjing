#include <iostream>
#include <string>

using namespace std;

string plusOne(string &s) {
    string res;
    bool neg = false;
    if (s[0] == '-') {
        neg = true;
        res = s.substr(1);
    } else
        res = s;

    if (neg) {
        for (int i = res.size()-1; i >= 0; i--) {
            if (res[i] == '0') {
                res[i] = '9';
            } else {
                res[i]--;
                break;
            }
        }
        if (res[0] == '0') {
            if (res.size() == 1)
                return "0";
            else 
                res = res.substr(1);
        } 
        return "-" + res;

    } else {
        for (int i = res.size()-1; i >= 0; i--) {
            if (res[i] == '9') {
                res[i] = '0';
            } else {
                res[i]++;
                break;
            }
        }
        return res[0] == '0'? ("1" + res) : res;
    }
}

int main() {
    string test1 = "129";
    cout << plusOne(test1) << endl;
    
    string test2 = "-10";
    cout << plusOne(test2) << endl;

    string test3 = "-1";
    cout << plusOne(test3) << endl;
    return 0;
}
