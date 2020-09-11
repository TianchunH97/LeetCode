// LeetCode 1489: Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

#include <vector>

using namespace std;

class Solution {
    typedef pair<int, int> PII;
    vector<int> pre;
    void initpre() {
        for (int i = 0; i < pre.size(); i++) {
            pre[i] = i;
        }
    }
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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<PII> weights;
        vector<vector<int>> ret(2);
        for (int i = 0; i < edges.size(); i++) {
            weights.push_back({edges[i][2], i});
        }
        sort(weights.begin(), weights.end());
        pre.resize(n);
        initpre();
        int min_cost = 0;
        for (PII w : weights) {
            if (find(edges[w.second][0]) == find(edges[w.second][1])) continue;
            else {
                pre[find(edges[w.second][0])] = find(edges[w.second][1]);
                min_cost += w.first;
            }
        }
        int cost;
        for (int i = 0; i < weights.size(); i++) {
            initpre();
            cost = 0;
            for (int j = 0; j < weights.size(); j++) {
                if (i == j) continue;
                if (find(edges[weights[j].second][0]) == find(edges[weights[j].second][1])) continue;
                else {
                    pre[find(edges[weights[j].second][0])] = find(edges[weights[j].second][1]);
                    cost += weights[j].first;
                }
            }
            if (find(edges[weights[i].second][0]) != find(edges[weights[i].second][1]) || cost > min_cost) {
                ret[0].push_back(weights[i].second);
                continue;
            }
            initpre();
            pre[edges[weights[i].second][0]] = edges[weights[i].second][1];
            cost = weights[i].first;
            for (int j = 0; j < weights.size(); j++) {
                if (i == j) continue;
                if (find(edges[weights[j].second][0]) == find(edges[weights[j].second][1])) continue;
                else {
                    pre[find(edges[weights[j].second][0])] = find(edges[weights[j].second][1]);
                    cost += weights[j].first;
                }
            }
            if (cost == min_cost) ret[1].push_back(weights[i].second);
        }
        return ret;
    }
};