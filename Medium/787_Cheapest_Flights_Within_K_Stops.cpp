// LeetCode 787: Cheapest Flights Within K Stops

#include <vector>

using namespace std;

class Solution {
    int cheapest;
    vector<vector<vector<int>>> graph;
    void dfs(int curr, int dst, int price, int K, vector<bool> &visited) {
        if (curr == dst && K >= 0) {
            cheapest = min(cheapest, price);
            return;
        }
        if (K <= 0 || price >= cheapest) return;
        visited[curr] = true;
        for (const auto& g : graph[curr]) {
            if (!visited[g[0]]) {
                dfs(g[0], dst, price+g[1], K-1, visited);
            }
        }
        visited[curr] = false;
        return;
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        cheapest = INT_MAX;
        graph.resize(n);
        for (const auto& f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }
        vector<bool> visited(n, false);
        dfs(src, dst, 0, K+1, visited);
        return cheapest < INT_MAX ? cheapest : -1;
    }
};