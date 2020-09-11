// LeetCode 1192: Critical Connections in a Network

#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> ret;
    int dfs(int v, int parent, int step, vector<int> &id) {
        id[v] = step + 1;
        for (int child : graph[v]) {
            if (child == parent) continue;
            if (id[child] == -1) id[v] = min(id[v], dfs(child, v, step+1, id));
            else id[v] = min(id[v], id[child]);
        }
        if (id[v] == step+1 && v != 0) ret.push_back({v, parent});
        return id[v];
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n);
        for (const auto& c : connections) {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        vector<int> id(n, -1);
        dfs(0, -1, 0, id);
        return ret;
    }  
};