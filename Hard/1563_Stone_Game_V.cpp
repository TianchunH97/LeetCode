// LeetCode 1563: Stone Game V

#include <vector>

using namespace std;

class Solution {
    int playGame(const vector<int> &stoneValue, int begin, int end, const vector<int> &sum, vector<vector<int>> &memo) {
        if (begin >= end) return 0;
        if (memo[begin][end] != -1) return memo[begin][end];
        int points = 0;
        int left, right, playleft, playright;
        for (int i = begin; i < end; i++) {
            left = sum[i+1] - sum[begin];
            right = sum[end+1] - sum[i+1];
            if (left > right) points = max(points, right + playGame(stoneValue, i+1, end, sum, memo));
            else if (right > left) points = max(points, left + playGame(stoneValue, begin, i, sum, memo));
            else points = max(points, left + max(playGame(stoneValue, begin, i, sum, memo), playGame(stoneValue, i+1, end, sum, memo)));
        }
        memo[begin][end] = points;
        return points;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        if (n == 0) return 0;
        vector<int> sum;
        int s = 0;
        sum.push_back(s);
        for (int v : stoneValue) {
            s += v;
            sum.push_back(s);
        }
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return playGame(stoneValue, 0, n-1, sum, memo);
    }
};