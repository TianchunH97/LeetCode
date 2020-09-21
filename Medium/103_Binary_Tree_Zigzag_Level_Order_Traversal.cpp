// LeetCode 103: Binary Tree Zigzag Level Order Traversal

#include <vector>
#include <deque>

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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ret;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left2right = 1;
        while (!dq.empty()) {
            int size = dq.size();
            vector<int> tmp;
            if (left2right) {
                for (int i = 0; i < size; i++) {
                    TreeNode* node = dq.front();
                    tmp.push_back(node->val);
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                }
                left2right = 0;
                ret.push_back(tmp);
            }
            else {
                for (int i = 0; i < size; i++) {
                    TreeNode* node = dq.back();
                    tmp.push_back(node->val);
                    dq.pop_back();
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
                left2right = 1;
                ret.push_back(tmp);
            }
        }
        return ret;
    }
};