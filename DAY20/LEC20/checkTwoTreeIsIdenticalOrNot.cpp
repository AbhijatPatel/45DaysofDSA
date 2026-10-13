
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

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr){
            return (p == q);
        }
        return(p->val == q->val) && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

int main() {
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);


    if (isSameTree(p, q))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
