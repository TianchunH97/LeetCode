// LeetCode 399: Evaluate Division

#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> ret;
    void dfs(string curr, string des, double val, unordered_set<string>& visited) {
        if (visited.count(curr)) return;
        if (!graph.count(curr)) return;
        if (curr == des) {
            visited.insert(des);
            ret[ret.size()-1] = val;
            return;
        }
        if (ret[ret.size()-1] != -1.0) return;
        visited.insert(curr);
        for (auto e : graph[curr]) {
            dfs(e.first, des, val*e.second, visited);
        }
        visited.erase(curr);
        return;
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        for (auto q : queries) {
            ret.push_back(-1.0);
            unordered_set<string> visited;
            dfs(q[0], q[1], 1.0, visited);
        }
        return ret;
    }
};