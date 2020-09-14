// LeetCode 872: Leaf-Similar Trees

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
    void getLeaves(vector<int> &tree, TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) tree.push_back(root->val);
        else {
            getLeaves(tree, root->left);
            getLeaves(tree, root->right);
        }
        return;
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1;
        vector<int> tree2;
        getLeaves(tree1, root1);
        getLeaves(tree2, root2);
        if (tree1.size() != tree2.size()) return false;
        for (int i = 0; i < tree1.size(); i++) {
            if (tree1[i] != tree2[i]) return false;
        }
        return true;
    }
};