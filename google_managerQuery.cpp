#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    list<TreeNode*> managers;
    string employID;
    TreeNode(const string &str) {
        employID = str;
    }
};

ostream &operator<<(ostream &os, const TreeNode &tn) {
    os << tn.employID << "'s manager: ";
    for (auto m : tn.managers) {
        os << m->employID << " ";
    }
    return os;
}

class Management {
public:
    void setManagement(const string &a, const string &b) {
        // set a as a direct manager of b;
        checkEmployee(a, b);
        id2node[b]->managers.push_back(id2node[a]);
    }

    void setPeer(const string &a, const string &b) {
        // set a and b to have the same direct manager
        checkEmployee(a, b);
        id2node[a]->managers = id2node[b]->managers;
    }

    bool inManagementChain(const string &a, const string &b) {
        // returns true if a is in the management chain of b
        if (checkEmployee(a, b) == false)
            return false;
        queue<TreeNode*> q;
        q.push(id2node[a]);
        
        while(!q.empty()) {
            TreeNode* cur = q.front();
            cout << cur->employID << endl;
            q.pop();
            for (auto neighbor : cur->managers) {
                if (neighbor == id2node[b])
                    return true;
                q.push(neighbor);
            }
        }
        return false;
    }

    bool checkEmployee(const string &a, const string &b) {
        bool exist = true;
        if (id2node.find(a) == id2node.end()) {
            people.emplace_back(a);
            id2node[a] = &people.back();
            exist = false;
        }
        if (id2node.find(b) == id2node.end()) {
            people.emplace_back(b);
            id2node[b] = &people.back();
            exist = false;
        }
        return exist;
    }

    void printPeople() {
        for (auto it = people.begin(); it!= people.end(); it++) {
            cout << *it << endl;
        }
        cout << endl;
    }

private:
    list<TreeNode> people;
    unordered_map<string, TreeNode*> id2node;
};


int main() {
    Management m;
    m.setManagement("A", "B");
    m.setManagement("B", "C");
    m.setPeer("D", "C");
    m.setPeer("E", "B");
    m.setManagement("F", "E");
    m.setManagement("F", "D");
    m.printPeople();
    //m.setPeer("B", "E");
    //m.setManagement("F", "E");
    //m.setManagement("F", "D");
    cout << m.inManagementChain("D", "A") << endl;
    return 0;
}
