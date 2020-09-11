// LeetCode 863: All Nodes Distance K in Binary Tree

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    void annotate(TreeNode* root) {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        annotate(root->left);
        annotate(root->right);
        return;
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        annotate(root);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        vector<int> ret;
        int dist = 0;
        q.push(target);
        visited.insert(target);
        while (!q.empty() && dist != K) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited.count(curr->left)) {
                    q.push(curr->left);
                    visited.insert(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    q.push(curr->right);
                    visited.insert(curr->right);
                }
                if (parent.count(curr) && !visited.count(parent[curr])) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]);
                }
            }
            dist++;
        }
        while (!q.empty()) {
            ret.push_back(q.front()->val);
            q.pop();
        }
        return ret;
    }
};