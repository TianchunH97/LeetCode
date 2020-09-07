// LeetCode 210: Course Schedule II

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
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
        if (q.empty()) return {};
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            ret.push_back(curr);
            indegrees.erase(curr);
            for (int v : after[curr]) {
                indegrees[v] -= 1;
                if (indegrees[v] == 0) q.push(v);
            }
        }
        if (indegrees.size()==0) return ret;
        else return {};
    }
};