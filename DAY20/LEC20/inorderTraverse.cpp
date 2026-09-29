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
// Inorder Traversal

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;

    //     TreeNode* current = root;

    //     while (current != NULL || !st.empty()) {
    //         while (current != NULL) {
    //             st.push(current);
    //             current = current->left;
    //         }

    //         current = st.top();
    //         st.pop();

    //         ans.push_back(current->val);

    //         current = current->right;
    //     }

    //     return ans;
    // }

    // Iterative Inorder Traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
         st.push(node);
        node = node->left; 
        }

        else{
            if(st.empty() == true)
            break;

            node = st.top();
            st.pop();

            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

int main() {

     TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = inorderTraversal(root);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}