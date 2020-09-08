// LeetCode 1319: Number of Operations to Make Network makeConnected

#include <vector>
#include <unordered_set>

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n == 1) return 0;
        if (connections.size() < n-1) return -1;
        pre.resize(n);
        for (int i = 0; i < n; i++) {
            pre[i] = i;
        }
        for (const auto & c : connections) {
            pre[find(c[0])] = find(c[1]);
        }
        unordered_set<int> roots;
        for (int i : pre) {
            roots.insert(find(i));
        }
        return roots.size()-1;
    }
};