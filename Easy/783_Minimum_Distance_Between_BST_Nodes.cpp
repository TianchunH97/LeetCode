// LeetCode 783: Minimum Distance Between BST Nodes

#include <vector>

using namespace std;

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
    vector<int> values;
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        values.push_back(root->val);
        traverse(root->right);
        return;
    }
public:
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        int diff = values[1] - values[0];
        for (int i = 2; i < values.size(); i++) {
            diff = min(diff, values[i] - values[i-1]);
        }
        return diff;
    }
};