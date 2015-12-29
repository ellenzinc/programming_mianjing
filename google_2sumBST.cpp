#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(){}
    TreeNode(int v): val(v) {}
};

ostream &operator<<(ostream &os, const vector<pair<int, int>> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        os << "(" << vec[i].first << ", " << vec[i].second << ")" << " ";
    }
    return os;
}

class TreeIterator {
public:
    TreeIterator(bool in, TreeNode* r): inorder(in), root(r) {}
    
    /* bool hasNext() {
        while (root) {
            st.push(root);
            root = inorder ? root->left : root->right;
        }
        return !st.empty();
        } */

    TreeNode* next() {
        while (root) {
            st.push(root);
            root = inorder ? root->left : root->right;
        }
        if (st.empty()) return NULL;
        cur = st.top();
        st.pop();
        root = inorder? cur->right : cur->left;
        return cur;
    }

    int getValue() {
        return cur->val;
    }
private:
    bool inorder = true;
    TreeNode* cur = NULL;
    TreeNode* root = NULL;
    stack<TreeNode*> st;
};

vector<pair<int, int> > find2Sum(TreeNode* root, int sum) {
    vector<pair<int, int> > res;
    TreeIterator inorderIter(true, root), reverseorderIter(false, root);
    TreeNode* ptr1 = inorderIter.next();
    TreeNode* ptr2 = reverseorderIter.next();
    while (ptr1 && ptr2 && ptr1->val < ptr2->val) {
        if (ptr1->val + ptr2->val > sum) {
            ptr2 = reverseorderIter.next();
        } else {
            if (ptr1->val + ptr2->val == sum) {
                res.emplace_back(ptr1->val, ptr2->val);
            }
            ptr1 = inorderIter.next();
        }
    }
    return res;
}


int main() {
    TreeNode node1(1), node2(2), node4(4), node5(5), node6(6), node7(7), node8(8), node9(9), 
        node10(10);
    node6.left = &node4;
    node6.right = &node9;
    node4.left = &node2;
    node4.right = &node5;
    node2.left = &node1;
    node9.left = &node7;
    node9.right = &node10;

    cout<<find2Sum(&node6, 9)<< endl;
    return 0;
}
