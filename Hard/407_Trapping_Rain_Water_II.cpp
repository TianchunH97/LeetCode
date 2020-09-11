// LeetCode 407: Trapping Rain Water II

#include <queue>
#include <vector>

using namespace std;

class Solution {
    typedef pair<int,int> PII;
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int M = heightMap.size();
        int N = heightMap[0].size();
        if (M < 3 || N < 3) return 0;
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        vector<vector<bool>> visited(M, vector<bool>(N, 0));
        vector<int> dir1 = {0, 0, -1, 1};
        vector<int> dir2 = {-1, 1, 0, 0};
        int water = 0;
        for (int j = 1; j < N-1; j++) {
            pq.push({heightMap[0][j], j});
            visited[0][j] = 1;
            pq.push({heightMap[M-1][j], (M-1)*N+j});
            visited[M-1][j] = 1;
        }
        for (int i = 1; i < M-1; i++) {
            pq.push({heightMap[i][0], i*N});
            visited[i][0] = 1; 
            pq.push({heightMap[i][N-1], (i+1)*N-1});
            visited[i][N-1] = 1;
        }
        visited[0][0] = 1;
        visited[0][N-1] = 1;
        visited[M-1][0] = 1;
        visited[M-1][N-1] = 1;
        while (!pq.empty()) {
            int height = pq.top().first;
            int pos = pq.top().second;
            pq.pop();
            int r = pos/N, c = pos%N;
            for (int i = 0; i < 4; i++) {
                if (r == 0 && i == 2) continue;
                if (r == M-1 && i == 3) continue;
                if (c == 0 && i == 0) continue;
                if (c == N-1 && i == 1) continue;
                if (visited[r+dir1[i]][c+dir2[i]]) continue;
                int h = heightMap[r+dir1[i]][c+dir2[i]];
                water += max(0, height - h);
                pq.push({max(height, h), (r+dir1[i])*N+c+dir2[i]});
                visited[r+dir1[i]][c+dir2[i]] = 1;
            }
        }
        return water;
    }
};