#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        stack<int> st;
        for (int i = 0; i < graph.size(); i++) {
            if (color[i]== 0) {
                color[i] = 1;
                st.push(i);
                while (!st.empty()) {
                    int t = st.top();
                    st.pop();
                    for (int v : graph[t]) { // color v from t
                        if (color[v] == color[t]) return false;
                        if (color[v] == 0) {
                            color[v] = -color[t];
                            st.push(v);
                        }
                    }
                }
            }
        }
        return true;
    }
};