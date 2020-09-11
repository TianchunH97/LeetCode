// LeetCode 101: Symmetric Tree

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isMirror(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        if (!A || !B || A->val != B->val) return false;
        return isMirror(A->left, B->right) && isMirror(A->right, B->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};