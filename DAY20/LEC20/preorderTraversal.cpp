#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> preorderTraversal(TreeNode* root) {

    vector<int> ans;
    stack<TreeNode*> st;

    if (root == NULL)
        return ans;

    st.push(root);

    while (!st.empty()) {

        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->val);

        if (node->right != NULL)
            st.push(node->right);

        if (node->left != NULL)
            st.push(node->left);
    }

    return ans;
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = preorderTraversal(root);

    cout << "Preorder Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}