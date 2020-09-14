// LeetCode 897: Increasing Order Search Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        else if (!root->left && !root->right) return root;
        else if (!root->left) {
            root->right = increasingBST(root->right);
            return root;
        }
        else {
            TreeNode* newroot = increasingBST(root->left);
            root->left = nullptr;
            TreeNode* tmp = newroot;
            while (tmp->right) {
                tmp = tmp->right;
            }
            tmp->right = increasingBST(root);
            return newroot;
        }
    }
};