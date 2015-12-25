#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

struct LogEntry {
    string candidate;
    int time;
    LogEntry(string c, int t): candidate(c), time(t) {}
};

string findWinner(int time, vector<LogEntry> &logs) {
    string res;
    unordered_map<string, int> hashLogs;
    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].time <= time) {
            hashLogs[logs[i].candidate]++;
        }
    }
    
    int num = 0;
    for (auto it = hashLogs.begin(); it != hashLogs.end(); it++) {
        if (num < it->second) {
            num = it->second;
            res = it->first;
        }
    }
    return res;
}

int main() {
    vector<LogEntry> logs = {LogEntry("c1", 1), LogEntry("c2", 2), LogEntry("c1", 2), LogEntry("c2", 3), LogEntry("c2", 4)};
    cout << findWinner(4, logs) << endl;
    return 0;
}
