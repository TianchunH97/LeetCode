// LeetCode 1368: Minimum Cost to Make at Least One Valid Path in a Grid

#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<vector<int>> dp(M, vector<int>(N, INT_MAX));
        deque<int> q;
        vector<int> dir1 = {0, 0, 1, -1};
        vector<int> dir2 = {1, -1, 0, 0};
        q.push_back(0);
        dp[0][0] = 0;
        while (!q.empty()) {
            int pos = q.front();
            int r = pos/N;
            int c = pos%N; 
            int cost = dp[r][c];
            if (r == M-1 && c == N-1) return cost;
            q.pop_front();
            for (int i = 0; i < 4; i++) {
                int nr = r + dir1[i];
                int nc = c + dir2[i];
                if (nr >= 0 && nc >= 0 && nr < M && nc < N) {
                    if (grid[r][c] == i+1) {
                        if (cost >= dp[nr][nc]) continue;
                        q.push_front(nr*N+nc);
                        dp[nr][nc] = cost;
                    }
                    else {
                        if (cost+1 >= dp[nr][nc]) continue;
                        q.push_back(nr*N+nc);
                        dp[nr][nc] = cost+1;
                    }
                }
            }
        }
        return -1;
    }
};