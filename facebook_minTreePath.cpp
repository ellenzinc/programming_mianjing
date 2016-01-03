#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &path) {
    for (int i = 0; i < path.size(); i++) {
        os << path[i] << " ";
    }
    return os;
}

struct TreeNode {
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int v): val(v){}
};

int bestPathHelper(TreeNode* root, vector<int> &path) {
    if (root == NULL)
        return INT_MAX;
    vector<int> tmp = path;
    int leftMin = bestPathHelper(root->left, path);
    int rightMin = bestPathHelper(root->right, tmp);
    if (leftMin > rightMin) {
        path = tmp;
    }
    path.push_back(root->val);
    return min(root->val, min(leftMin, rightMin));
}

vector<int> bestPath(TreeNode* root) {
    vector<int> path;
    bestPathHelper(root, path);
    return path;
}

int main() {
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7), node8(8);
    node6.left = &node4;
    node6.right = &node5;
    node4.left = &node3;
    node4.right = &node2;
    node5.left = &node7;
    node5.right = &node1;
    //node1.left = &node8;
    cout << bestPath(&node6) << endl;

    return 0;
}
