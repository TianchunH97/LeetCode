// LeetCode 547: Friend Circles

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<bool> visited(N, false);
        int count = 0;
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            count++;
            visited[i] = 1;
            for (int j = 0; j < N; j++) {
                if (M[i][j] == 1 && !visited[j] && i != j) {
                    st.push(j);
                    visited[j] = 1;
                }
            }
            while (!st.empty()) {
                int t = st.top();
                st.pop();
                for (int k = 0; k < N; k++) {
                    if (M[t][k] == 1 && !visited[k] && t != k) {
                        st.push(k);
                        visited[k] = 1;
                    }
                }
            }
        }
        return count;
    }
};