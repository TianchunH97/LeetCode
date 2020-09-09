// LeetCode 695: Max Area of Island

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int M = grid.size();
        if (M == 0) return 0;
        int N = grid[0].size();
        int maxarea = 0, tmpmax = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    tmpmax = 1;
                    q.push({i,j});
                    grid[i][j] = 0;
                    while (!q.empty()) {
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        if (a-1 >= 0 && grid[a-1][b] == 1) {
                            q.push({a-1,b});
                            grid[a-1][b] = 0;
                            tmpmax += 1;
                        }
                        if (a+1 < M && grid[a+1][b] == 1) {
                            q.push({a+1,b});
                            grid[a+1][b] = 0;
                            tmpmax += 1;
                        }
                        if (b-1 >= 0 && grid[a][b-1] == 1) {
                            q.push({a,b-1});
                            grid[a][b-1] = 0;
                            tmpmax += 1;
                        }
                        if (b+1 < N && grid[a][b+1] == 1) {
                            q.push({a,b+1});
                            grid[a][b+1] = 0;
                            tmpmax += 1;
                        }
                    }
                    if (tmpmax > maxarea) maxarea = tmpmax;
                }
            }
        }
        return maxarea;
    }
};