// LeetCode 685: Redundant Connection II

#include <vector>

using namespace std;

class Solution {
    vector<int> pre;
    int find(int root) { // union find with path compression
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        pre.resize(N+1);
        for (int i = 0; i < N+1; i++) {
            pre[i] = i;
        }
        vector<int> indegrees(N+1, 0);
        int node = -1;
        for (int i = 0; i < N; i++) {
            indegrees[edges[i][1]] += 1;
            if (indegrees[edges[i][1]] == 2) {
                node = edges[i][1];
                break;
            }
        }
        int a = -1, b = -1;
        if (node != -1) { // there is a node with indegree = 2
            for (auto e : edges) {
                if (e[1] != node) pre[find(e[0])] = find(e[1]);
                else if (a == -1) a = e[0];
                else b = e[0];
            }
            if (find(a) == find(node)) return {a, node};
            else return {b, node};
        }
        else { // circle
            for (auto e : edges) {
                if (find(e[0]) != find(e[1])) pre[find(e[0])] = find(e[1]);
                else return {e[0], e[1]};
            }
        }
        return {};
    }
};