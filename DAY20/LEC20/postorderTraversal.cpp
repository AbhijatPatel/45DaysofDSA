#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL)
        return ans;

    stack<TreeNode*> st1, st2;

    st1.push(root);

    while (!st1.empty()) {
        TreeNode* current = st1.top();
        st1.pop();

        st2.push(current);

        if (current->left != NULL)
            st1.push(current->left);

        if (current->right != NULL)
            st1.push(current->right);
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> ans = postorderTraversal(root);

    cout << "Postorder Traversal: ";

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}