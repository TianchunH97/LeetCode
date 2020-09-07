// LeetCode 1042: Flower Planting With No Adjacent

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> graph(N);
        for (auto p : paths) {
            graph[p[0]-1].push_back(p[1]-1);
            graph[p[1]-1].push_back(p[0]-1);
        }
        vector<int> color(N, 0);
        unordered_set<int> tmp;
        for (int i = 0; i < N; i++) {
            tmp.clear();
            for (int v : graph[i]) {
                tmp.insert(color[v]);
            }
            for (int j = 1; j < 5; j++) {
                if (!tmp.count(j)) {
                    color[i] = j;
                    break;
                }
            }
        }
        return color;
    }
};