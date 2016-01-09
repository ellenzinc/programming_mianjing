#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v) : val(v) {}
};

int getDepth(TreeNode *root) {
    int depth = 0;
    while (root) {
        depth++;
        root = root->left;
    }
    return depth;
}

TreeNode* findLastNode(TreeNode *root) {
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    if (getDepth(root->left) > getDepth(root->right)) {
        return findLastNode(root->left);
    } else {
        return findLastNode(root->right);
    }
}



int main() {
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    TreeNode* node = findLastNode(&node1);
    if (node)
        cout << node->val << endl;
    return 0;
}
