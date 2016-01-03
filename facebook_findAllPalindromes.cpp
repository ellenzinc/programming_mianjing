#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

ostream &operator<<(ostream &os, const vector<pair<string, string> > &vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << "(" << vec[i].first << ", " << vec[i].second << ")" << endl;
    }
    return os;
}

bool isPalindrome(const string &s, int start, int end) {
    if (start > end) 
        return true;
    while (start <= end && s[start++] == s[end--]) {}
    return start > end;

}

vector<pair<string, string> > 
palindromePair(const vector<string> &words) {
    vector<pair<string, string> > res;
    unordered_set<string> dict(words.begin(), words.end());

    for (int i = 0; i < words.size(); i++) {
        int len = words[i].size();
        // l is the length of the first part;
        for (int l = 0; l <= len; l++) {
            if (isPalindrome(words[i], 0, l+0-1)) {
                string tmp = words[i].substr(l+0, len-l);
                reverse(tmp.begin(), tmp.end());
                if (dict.find(tmp) != dict.end()) {
                    res.emplace_back(tmp, words[i]);
                }
            }
            if (isPalindrome(words[i], l+0, len-1)) {
                string tmp = words[i].substr(0, l);
                reverse(tmp.begin(), tmp.end());
                if (dict.find(tmp) != dict.end()) {
                    res.emplace_back(words[i], tmp);
                }
            }
        }
    }
    return res;

}

int main() {
    cout << palindromePair({"tacoto", "bat", "tabloid", "cat","ototac", "junk"}) << endl;
    return 0;
}
