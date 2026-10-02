#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode* left, TreeNode* right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};


    int maxDepth(TreeNode* root) {

        // Base case
        if (root == NULL)
            return 0;

        // Find depth of left subtree
        int leftDepth = maxDepth(root->left);

        // Find depth of right subtree
        int rightDepth = maxDepth(root->right);

        // Current node adds 1
        return max(leftDepth, rightDepth) + 1;
    }


int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);


    int answer = maxDepth(root);

    cout << "Maximum Depth: " << answer << endl;

    return 0;
}