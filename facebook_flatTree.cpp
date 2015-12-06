#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* flattenTreeHelper(TreeNode* root, TreeNode* &prev) {
    if (root == NULL) return NULL;
    TreeNode* top1 = flattenTreeHelper(root->left, prev);
    if (prev){
        prev->right = root;
        prev->left = NULL;
    }
    prev = root;
    TreeNode* top2 = flattenTreeHelper(root->right, prev);
    root->left = NULL;
    return top1 == NULL ? root : top1;
}

TreeNode* flattenTreeNonRecurse(TreeNode* root);

void printFlattenTree(TreeNode* root) {
    while(root) {
        cout << root->val << " ";
        if (root->left) {
            cout << "Not right!" << root->left->val << endl;
        }
        root = root->right;
    }
    cout << endl;
}

void flattenTree(TreeNode* root) {
    TreeNode* prev = NULL;
    root = flattenTreeNonRecurse(root);
    printFlattenTree(root);
}

TreeNode* flattenTreeNonRecurse(TreeNode* root) {
    if (root == NULL) return NULL;
    stack<TreeNode*> st;
    TreeNode* newRoot = NULL;
    TreeNode* prev = NULL;
    while(true) {
        while(root) {
            st.push(root);
            root = root->left;
        }
        if (st.empty()) return newRoot;
        TreeNode* cur = st.top();
        st.pop();
        if (prev == NULL) {
            cur->left = NULL;
            newRoot = cur;
        } else {
            prev->right = cur;
            cur->left = NULL;
        }
        prev = cur;

        if (cur->right) {
            root = cur->right;
        }
        cur->right = NULL;
    }
    return newRoot;
}

int main() {
    TreeNode node0(2), node1(4), node2(5), node3(6), node4(7), node5(8), node6(9);
    node1.left = &node0;
    node1.right = &node2;
    node3.left = &node1;
    node3.right = &node6;
    node6.left = &node4;
    node4.right = &node5;
    flattenTree(&node3);
    return 0;
}
