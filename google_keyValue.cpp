#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <deque>

using namespace std;

template<typename keyT, typename valT>
class KeyValueStore {
public:
    void insertVal(keyT key, valT val) {
        indices.push_back(key);
        int idx = indices.size()-1;
        dataStore[key] = make_pair(idx, val);
    }
    
    void deleteKey(keyT key) {
        if (dataStore.count(key) == 0) return;
        int idx = dataStore[key].first;
        int endKey = indices.back();
        swap(indices[idx], indices.back());
        dataStore[endKey].first= idx;
        dataStore.erase(key);
        indices.pop_back();
    }

    valT getRandom() {
        random_device rd;
        default_random_engine e1(rd());
        uniform_int_distribution<int> uniformDist(0, indices.size()-1);
        int idx = uniformDist(e1);
        return dataStore[indices[idx]].second;
    }

    void printData() {
        cout << "indices:" << endl;
        for (int i = 0; i < indices.size(); i++) {
            cout << indices[i] << " ";
        }
        cout << endl << "dataStore:" << endl;
        for (auto it = dataStore.begin(); it!= dataStore.end(); it++) {
            cout << it->first << ": index " << it->second.first << ", value: "
                 << it->second.second << endl; 
        }
    }
private:
    deque<keyT> indices;
    unordered_map<keyT, pair<int, valT> > dataStore;
};

int main() {
    KeyValueStore<char, int> kvs;
    kvs.insertVal('a',4);
    kvs.insertVal('b',5);
    kvs.insertVal('e',2);
    kvs.insertVal('f',0);
    kvs.printData();
    cout << kvs.getRandom() << endl;
    kvs.deleteKey('e');
    kvs.printData();
    return 0;
}
