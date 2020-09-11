// LeetCode 815: Bus Routes

#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int N = routes.size();
        unordered_map<int, unordered_set<int>> graph;
        for (int i = 0; i < N; i++) {
            for (int j : routes[i]) {
                graph[j].insert(i);
            }            
        }
        vector<bool> visited(N, false);
        queue<int> q;
        unordered_set<int> last;
        for (int bus : graph[T]) {
            last.insert(bus);
        }
        int count = 2;
        for (int bus : graph[S]) {
            if (last.count(bus)) return 1;
            q.push(bus);
            visited[bus] = 1;
        }
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int b = q.front();
                q.pop();
                for (int stop : routes[b]) {
                    for (int r : graph[stop]) {
                        if (last.count(r)) return count;
                        if (!visited[r]) {
                            q.push(r);
                            visited[r] = 1;
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};