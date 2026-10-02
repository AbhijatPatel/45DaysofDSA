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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if (root == NULL)
        return ans;

    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        vector<int> level;

        for (int i = 0; i < size; i++) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);

            level.push_back(node->val);
        }

        ans.push_back(level);
    }

    return ans;
}

int main() {

    // Creating the tree
    //
    //         1
    //        / \
    //       2   3
    //      / \   \
    //     4   5   6

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->right = new TreeNode(6);

    vector<vector<int>> ans = levelOrder(root);

    cout << "Level Order Traversal:" << endl;

    for (vector<int> level : ans) {

        cout << "[ ";

        for (int value : level) {
            cout << value << " ";
        }

        cout << "]" << endl;
    }

    return 0;
}