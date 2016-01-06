#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

struct LogData {
    string name;
    int timeStamp;
    bool start;
    LogData(): start(false){}
    LogData(const string &n, int t, bool s): name(n), timeStamp(t), start(s) {}
};

struct Record {
    string name;
    int totalTime = 0;
    int startTime = 0;
    Record() {}
    Record(const string &n, int t, int s): name(n), totalTime(t), startTime(s) {}
};

template<typename T1, typename T2> 
ostream &operator<< (ostream &os, const unordered_map<T1, T2> &m) {
    for (auto it = m.begin(); it != m.end(); it++) {
        os << it->first << ": " << it->second << endl;
    }
    return os;
}

unordered_map<string, int> calculateExecutionTime(vector<LogData> &data) {
    stack<Record> st;
    unordered_map<string, int> res;
    for (int i = 0; i < data.size(); i++) {
        if (st.empty()) {
            st.push(Record(data[i].name, 0, data[i].timeStamp));
        } else if (st.top().name == data[i].name) {
            res[data[i].name] = st.top().totalTime + data[i].timeStamp-st.top().startTime;
            st.pop();
            if (!st.empty()) {
                st.top().startTime = data[i].timeStamp;
            }
        } else {
            st.top().totalTime += (data[i].timeStamp - st.top().startTime);
            st.push(Record(data[i].name, 0, data[i].timeStamp));
        }
    }
    return res;
}

int main() {
    vector<LogData> data = {LogData("f1", 0, true), LogData("f2", 2, true), 
                            LogData("f2", 6, false), LogData("f1", 8, false),
                            LogData("f3", 11, true), LogData("f3", 12, false)};
    cout << calculateExecutionTime(data) << endl;

    return 0;
}
