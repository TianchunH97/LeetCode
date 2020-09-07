// LeetCode 332: Reconstruct Itinerary

#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> paths;
    stack<string> st;
    void dfs(string curr) {
        while (paths.count(curr) && paths[curr].size() > 0) {
            string next = paths[curr].top();
            paths[curr].pop();
            dfs(next);
        }
        st.push(curr);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t : tickets) {
            paths[t[0]].push(t[1]);
        }
        dfs("JFK");
        vector<string> ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        return ret;
    }
};