// LeetCode 743: Network Delay Time

#include <vector>

using namespace std;

class Solution {
    vector<int> time;
    vector<vector<pair<int,int>>> graph;
    void dfs(int curr, int spent) {
        if (time[curr] != -1 && spent >= time[curr]) return;
        time[curr] = spent;
        for (auto vw : graph[curr]) {
            dfs(vw.second, spent+vw.first);
        }
        return;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        graph.resize(N+1);
        time.resize(N+1);
        for (auto t : times) {
            graph[t[0]].push_back({t[2], t[1]});
        }
        for (int i = 1; i < N+1; i++) {
            sort(graph[i].begin(), graph[i].end());
        }
        for (int i = 0; i < N+1; i++) {
            time[i] = -1;
        }
        dfs(K, 0);
        int delay = 0;
        for (int i = 1; i < N+1; i++) {
            if (time[i] == -1) return -1;
            else delay = max(delay, time[i]);
        }
        return delay;
    }
};