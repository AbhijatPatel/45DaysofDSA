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

    int diameter = 0;

    int height(TreeNode* root) {

        // Base case
        if (root == NULL)
            return 0;

        // Find left subtree height
        int leftHeight = height(root->left);

        // Find right subtree height
        int rightHeight = height(root->right);

        // Diameter passing through current node
        diameter = max(diameter, leftHeight + rightHeight);

        // Return height of current node
        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }


int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    int answer = diameterOfBinaryTree(root);

    cout << "Diameter of Binary Tree: " << answer << endl;

    return 0;
}