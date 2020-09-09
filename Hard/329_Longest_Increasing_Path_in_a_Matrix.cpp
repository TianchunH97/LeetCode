// LeetCode 329: Longest Increasing Path in a Matrix

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int M = matrix.size();
        if (M == 0) return 0;
        int N = matrix[0].size();
        stack<pair<int,int>> st;
        int count = 0;
        int pos = 0;
        vector<vector<int>> dp(M, vector<int>(N,0));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dp[i][j] > 0) continue;
                if (j != 0 && matrix[i][j] > matrix[i][j-1]) continue;
                if (i != 0 && matrix[i][j] > matrix[i-1][j]) continue;
                if (j != N-1 && matrix[i][j] > matrix[i][j+1]) continue;
                if (i != M-1 && matrix[i][j] > matrix[i+1][j]) continue;
                st.push({N*i+j, 1});
                while (!st.empty()) {
                    pos = st.top().first;
                    int x = pos/N;
                    int y = pos%N;
                    int length = st.top().second;
                    st.pop();
                    if (dp[x][y] >= length) continue;
                    count = max(count, length);
                    dp[x][y] = length;
                    if (y > 0 && matrix[x][y] < matrix[x][y-1] && dp[x][y-1] < length+1) {
                        st.push({x*N+y-1, length+1}); 
                    }
                    if (x > 0 && matrix[x][y] < matrix[x-1][y] && dp[x-1][y] < length+1) {
                        st.push({(x-1)*N+y, length+1});
                    }
                    if (y < N-1 && matrix[x][y] < matrix[x][y+1] && dp[x][y+1] < length+1) {
                        st.push({x*N+y+1, length+1});
                    }
                    if (x < M-1 && matrix[x][y] < matrix[x+1][y] && dp[x+1][y] < length+1) {
                        st.push({(x+1)*N+y, length+1}); 
                    }
                }
            }
        }
        return count;
    }
};