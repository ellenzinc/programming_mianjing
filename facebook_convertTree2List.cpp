#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int v): val(v) {}
};

TreeNode* convertTree2List(TreeNode* root) {
    TreeNode* head = NULL;
    TreeNode* prev = NULL;
    stack<TreeNode*> st;
    while (true) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            break;
        root = st.top();
        st.pop();
        if (head == NULL)
            head = root;
        if (prev) {
            prev->right = root;
            root->left = prev;
        }
        prev = root;
        root = root->right;
    }
    prev->right = head;
    head->left = prev;
    return head;
}

void printList(TreeNode* root) {
    TreeNode* head = root;
    while (root && root->right != head) {
        cout << root->val << "->";
        root = root->right;
    }
    if (root)
        cout << root->val;
    cout <<  endl;
    head = root;
    while (root && root->left != head) {
        cout << root->val << "<-";
        root = root->left;
    }
    if (root)
        cout << root->val;
    cout << endl;
}

int main() {
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5), node6(6), node7(7);
    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.right = &node6;
    node6.left = &node7;
    printList(convertTree2List(&node1));
    return 0;
}
