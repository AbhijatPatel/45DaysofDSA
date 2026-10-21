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

    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void addLeftBoundary(TreeNode* root, vector<int>& ans) {

        TreeNode* node = root->left;

        while (node != nullptr) {

            if (!isLeaf(node))
                ans.push_back(node->val);

            if (node->left != nullptr)
                node = node->left;
            else
                node = node->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {

        if (root == nullptr)
            return;

        if (isLeaf(root)) {
            ans.push_back(root->val);
            return;
        }

        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    void addRightBoundary(TreeNode* root, vector<int>& ans) {

        vector<int> temp;

        TreeNode* node = root->right;

        while (node != nullptr) {

            if (!isLeaf(node))
                temp.push_back(node->val);

            if (node->right != nullptr)
                node = node->right;
            else
                node = node->left;
        }

        reverse(temp.begin(), temp.end());

        for (int value : temp)
            ans.push_back(value);
    }

    vector<int> boundaryTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == nullptr)
            return ans;

        if (!isLeaf(root))
            ans.push_back(root->val);

        addLeftBoundary(root, ans);

        addLeaves(root, ans);

        addRightBoundary(root, ans);

        return ans;
    }

int main() {

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";

    for (int value : result) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}