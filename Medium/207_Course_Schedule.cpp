// LeetCode 207: Course Schedule

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size()==0) return true;
        unordered_map<int, int> indegrees;
        vector<vector<int>> after(numCourses);
        for (int i = 0; i < numCourses; i++) {
            indegrees[i] = 0;
        }
        for (auto p : prerequisites) {
            indegrees[p[0]] += 1;
            after[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for (auto it=indegrees.begin(); it!=indegrees.end();it++) {
            if (it->second == 0) q.push(it->first);
        }
        if (q.empty()) return false;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            indegrees.erase(curr);
            for (int v : after[curr]) {
                indegrees[v] -= 1;
                if (indegrees[v] == 0) q.push(v);
            }
        }
        return indegrees.size()==0;
    }
};