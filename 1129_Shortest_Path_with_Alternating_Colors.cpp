// LeetCode 1129: Shortest Path with Alternating Colors

# include <vector>

using namespace std;

class Solution {
    vector<vector<int>> shortest;
    vector<vector<int>> red_paths;
    vector<vector<int>> blue_paths;
    void dfs(int curr, int length, char color) {
        if (color == 'b' && shortest[curr][1] != -1 && length >= shortest[curr][1]) return;
        if (color == 'r' && shortest[curr][0] != -1 && length >= shortest[curr][0]) return;
        if (color == 'b') shortest[curr][1] = length;
        else shortest[curr][0] = length;
        if (color == 'b') {
            for (int i : red_paths[curr]) {
                dfs(i, length+1, 'r');
            }
        }
        else {
            for (int i : blue_paths[curr]) {
                dfs(i, length+1, 'b');
            }
        }
        return;
    }
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        shortest.resize(n);
        for (int i = 0; i < n; i++) {
            shortest[i] = {-1,-1};
        }
        red_paths.resize(n);
        blue_paths.resize(n);
        for (auto e : red_edges) {
            red_paths[e[0]].push_back(e[1]);
        }
        for (auto e : blue_edges) {
            blue_paths[e[0]].push_back(e[1]);
        }
        dfs(0, 0, 'r');
        dfs(0, 0, 'b');
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            if (shortest[i][0] == -1 && shortest[i][1] == -1) ret[i] = -1;
            else if (shortest[i][0] == -1) ret[i] = shortest[i][1];
            else if (shortest[i][1] == -1) ret[i] = shortest[i][0];
            else ret[i] = min(shortest[i][1], shortest[i][0]);
        }
        return ret;
    }
};