// LeetCode 882: Reachable Nodes In Subdivided Graph

#include <vector>
#include <queue>

using namespace std;

class Solution {
    typedef pair<int, int> PII;
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<vector<PII>> graph(N);
        vector<bool> reached(N, false);
        vector<vector<int>> remain(N, vector<int>(N, 0));
        int cnt = 0;
        for (const auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra's Algorithm
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({0,0});
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (reached[node]) continue;
            reached[node] = true;
            cnt ++;
            for (const auto& nb : graph[node]) {
                if (nb.second+dis+1 <= M) { // can reach this neighbour
                    pq.push({dis+nb.second+1, nb.first});
                    remain[node][nb.first] = nb.second;
                }
                else remain[node][nb.first] = M-dis;
            }
        }
        for (const auto& e : edges) {
            cnt += min(e[2], remain[e[0]][e[1]]+remain[e[1]][e[0]]);
        }
        return cnt;
    }
};