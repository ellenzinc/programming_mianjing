#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v): val(v) {}
};

int findPathHelper(TreeNode* root, int &res) {
    if (root == NULL) return 0;
    int cur = 1;
    if (root->left) {
        int tmp = findPathHelper(root->left, res);
        if (root->left->val > root->val)
            cur += tmp;
    } 
    if (root->right) {
        int tmp = findPathHelper(root->right, res);
        if (root->right->val > root->val)
            cur = max(tmp+1, cur);
    }
    res = max(res, cur);
    return cur;
}

int findLongestIncreasingPath(TreeNode* root) {
    int res = 0;
    findPathHelper(root, res);
    return res;
}

int main() {
    TreeNode node1(8), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7), node8(8), 
        node9(9);
    node4.left = &node2;
    node4.right = &node8;
    node2.left = &node6;
    node2.right= &node3;
    node3.left = &node7;
    node3.right = &node5;
    node7.right = &node1;
    node8.left = &node7;
    node8.right = &node9;

    cout << findLongestIncreasingPath(&node4) << endl;
    return 0;
}
