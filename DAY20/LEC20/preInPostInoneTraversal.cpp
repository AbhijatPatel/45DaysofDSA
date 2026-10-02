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

// void allTraversals(
//     TreeNode* root,
//     vector<int>& preorder,
//     vector<int>& inorder,
//     vector<int>& postorder
// ) {
//     if (root == NULL)
//         return;

//     stack<pair<TreeNode*, int>> st;

//     st.push({root, 1});

//     while (!st.empty()) {

//         TreeNode* node = st.top().first;
//         int state = st.top().second;

//         // State 1: Preorder
//         if (state == 1) {

//             preorder.push_back(node->val);

//             st.top().second = 2;

//             if (node->left != NULL) {
//                 st.push({node->left, 1});
//             }
//         }

//         // State 2: Inorder
//         else if (state == 2) {

//             inorder.push_back(node->val);

//             st.top().second = 3;

//             if (node->right != NULL) {
//                 st.push({node->right, 1});
//             }
//         }

//         // State 3: Postorder
//         else {

//             postorder.push_back(node->val);

//             st.pop();
//         }
//     }
// }

vector<vector<int>> treeTraversal(TreeNode* root) {
    vector<int> pre, in, post;

    if (root == NULL) {
        return {};
    }

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->left != NULL) {
                st.push({it.first->left, 1});
            }
        } else if (it.second == 2) {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);

            if (it.first->right != NULL) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first->val);
        }
    }

    return {pre, in, post};
}

int main() {
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<vector<int>> traversals = treeTraversal(root);

    cout << "Preorder: ";
    for (int x : traversals[0]) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Inorder: ";
    for (int x : traversals[1]) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Postorder: ";
    for (int x : traversals[2]) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}