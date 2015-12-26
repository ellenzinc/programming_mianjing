#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct Node {
    int val = 0;
    unordered_set<int> children;
    Node(int v): val(v) {}
    Node(){}
};

ostream &operator<<(ostream &os, const vector<vector<int> > mtx) {
    for (int i = 0; i < mtx.size(); i++) {
        for (int j = 0; j < mtx[i].size(); j++) {
            os << mtx[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

vector<int> findInterSect(unordered_set<int> &a, unordered_set<int> &b, int low) {
    if (a.size() > b.size()) {
        return findInterSect(b, a, low);
    }
    vector<int> res;
    for (int val : a) {
        if (low < val && b.count(val))
            res.push_back(val);
    }
    return res;
}

vector<vector<int>> findAllTriangles(vector<Node> &graph) {
    int n = graph.size();
    vector<vector<int>> result;
    for (int i = 0; i < n; i++) {
        for (int child : graph[i].children) {
            if (child > i) {
                vector<int> nodes = findInterSect(graph[i].children, graph[child].children, child);
                for (int node : nodes) {
                    result.push_back({graph[i].val, graph[child].val, graph[node].val});
                }
            }
        }
    }
    return result;
}

int main() {
    vector<Node> graph = {Node(1), Node(2), Node(3), Node(4), Node(5), Node(6)};
    graph[0].children = {1, 2, 4, 5};
    graph[1].children = {0, 2, 3, 4};
    graph[2].children = {0, 1, 3};
    graph[3].children = {1, 2, 5};
    graph[4].children = {0, 1, 5};
    graph[5].children = {0, 3, 4};
    cout << findAllTriangles(graph) << endl;
    return 0;
}
