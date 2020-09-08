// LeetCode 684: Redundant Connection

#include <vector>

using namespace std;

class Solution {
    vector<int> pre;
    int find(int root) {
        if (root == pre[root]) return root;
        int son = root;
        int tmp;
        while (root != pre[root]) {
            root = pre[root];
        }
        while (son != root) {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size = edges.size();
        pre.resize(size+1);
        for (int i = 0; i <= size; i++) {
            pre[i] = i;
        }
        for (const auto& e : edges) {
            if (find(e[0]) == find(e[1])) return {e[0], e[1]};
            pre[find(e[0])] = find(e[1]);
        }
        return {0,0};
    }
};