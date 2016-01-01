#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

ostream &operator<<(ostream &os, const deque<char> &dq) {
    for (char c: dq) {
        os << c << " ";
    }
    return os;
}

bool inBuffer(deque<char> &dq, char a) {
    for (char c : dq) {
        if (c == a)
            return true;
    }
    return false;
}

int totalTime(const string &s, int k) {
    deque<char> buffer;
    int i = 0;
    int res = 0;
    while (i < s.length()) {
        //        cout << buffer << endl;
        // cout << s[i] << " is in buffer  " << buffer <<"? "<< inBuffer(buffer, s[i]) << endl;
        if (!inBuffer(buffer, s[i])) {
            cout << s[i] << endl;
            buffer.push_back(s[i++]);
        } else {
            cout << '_' << endl;
            buffer.push_back('_');
        }

        res++;
        if (buffer.size() >= k) {
            buffer.pop_front();
        }
    }
    cout << endl;
    return res;
}

int main() {
    cout << totalTime("AABABCCB", 3) << endl;
    return 0;
}
