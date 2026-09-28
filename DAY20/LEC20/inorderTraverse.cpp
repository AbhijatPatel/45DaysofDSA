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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        TreeNode* current = root;

        while (current != NULL || !st.empty()) {
            while (current != NULL) {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            ans.push_back(current->val);

            current = current->right;
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution obj;

    vector<int> result = obj.inorderTraversal(root);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}