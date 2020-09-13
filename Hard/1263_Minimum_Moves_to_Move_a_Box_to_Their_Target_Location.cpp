// LeetCode 1263: Minimum Moves to Move a Box to Their Target Location

#include <deque>
#include <vector>

using namespace std;

class Solution {
    typedef pair<int, pair<int, int>> PIII;
public:
    int minPushBox(vector<vector<char>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        deque<PIII> dq;
        int box = -1, start = -1;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'B') box = i*N+j;
                if (grid[i][j] == 'S') start = i*N+j;  
            }
        }
        dq.push_back({0, {box, start}});
        vector<vector<bool>> visited(M*N, vector<bool>(M*N, false));
        int dir1[] = {0, 0, -1, 1};
        int dir2[] = {-1, 1, 0, 0};
        while (!dq.empty()) {
            int push = dq.front().first;
            int b_pos = dq.front().second.first;
            int p_pos = dq.front().second.second;
            dq.pop_front();
            if (visited[b_pos][p_pos]) continue;
            visited[b_pos][p_pos] = true;
            int rb = b_pos/N, cb = b_pos%N;
            int rp = p_pos/N, cp = p_pos%N;
            for (int i = 0; i < 4; i++) {
                int nr = rp + dir1[i];
                int nc = cp + dir2[i];
                if (nr < 0 || nc < 0 || nr >= M || nc >= N || grid[nr][nc] == '#') continue;
                if (nr*N+nc != b_pos) {
                    dq.push_front({push, {b_pos, nr*N+nc}});
                }
                else { // move box
                    int nrb = rb + dir1[i], ncb = cb+dir2[i];
                    if (nrb < 0 || ncb < 0 || nrb >= M || ncb >= N || grid[nrb][ncb] == '#') continue;
                    if (grid[nrb][ncb] == 'T') return push+1;
                    dq.push_back({push+1, {nrb*N+ncb, b_pos}});
                }
            }
        }
        return -1;
    }
};