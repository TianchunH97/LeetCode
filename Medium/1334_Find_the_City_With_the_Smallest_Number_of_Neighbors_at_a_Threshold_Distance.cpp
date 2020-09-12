// LeetCode 1334: Find the City With the Smallest Number of Neighbors at a Threshold Distance

#include <vector>

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, 20000));
        for (const auto& e : edges) {
            dp[e[0]][e[1]] = e[2];
            dp[e[1]][e[0]] = e[2];
        }
        // Floyd Warshall Algorithm
        for (int k = 0; k < n; k++) { // Important! 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
                }
            }
        }
        int ret = 0;
        int min_count = n;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dp[i][j] <= distanceThreshold) count++;
            }
            if (count <= min_count) {
                min_count = count;
                ret = i;
            }
        }
        return ret;
    }
};