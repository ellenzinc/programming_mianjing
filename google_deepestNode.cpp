#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v): val(v) {}
};

void findDeepestNodeDFS(TreeNode* root, int depth, int &deepest, TreeNode* &res) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        if (deepest < depth) {
            deepest = depth;
            res = root;
        }
        return;
    }
    if (root->left) 
        findDeepestNodeDFS(root->left, depth+1, deepest, res);
    if (root->right)
        findDeepestNodeDFS(root->right, depth+1, deepest, res);
}

void findDeepestNodeBFS(TreeNode* root, TreeNode* &res) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size(); 
        for (int i = 0; i < n; i++) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right) 
                q.push(cur->right);
        }
        if (!q.empty()) {
            res = q.front();
        }
    }
}

TreeNode* findDeepestNode(TreeNode* root) {
    int deepest = 0;
    TreeNode* res = NULL;
    findDeepestNodeBFS(root, res);
    //findDeepestNodeDFS(root, 0, deepest, res);
    return res;
}

int main() {
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7), node8(8), 
        node9(9), node10(10);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node5.left = &node7;
    node5.right = &node8;
    node3.right = &node6;
    node8.left = &node10;
    node6.left = &node9;

    cout << findDeepestNode(&node1)->val << endl;
    return 0;
}
