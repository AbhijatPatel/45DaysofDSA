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

class Solution {
public:

    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root) {

        // Empty tree is balanced
        if (root == NULL)
            return 0;

        // Calculate left subtree height
        int leftHeight = dfsHeight(root->left);

        // Left subtree is not balanced
        if (leftHeight == -1)
            return -1;

        // Calculate right subtree height
        int rightHeight = dfsHeight(root->right);

        // Right subtree is not balanced
        if (rightHeight == -1)
            return -1;

        // Check current node
        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        // Return height of current subtree
        return max(leftHeight, rightHeight) + 1;
    }
};

int main() {

 

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    if (obj.isBalanced(root)) {
        cout << "The tree is Balanced" << endl;
    }
    else {
        cout << "The tree is Not Balanced" << endl;
    }

    return 0;
}