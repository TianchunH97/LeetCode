// LeetCode 1494: Parallel Courses II

#include <vector>

using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> prereq(n, 0);
        for (auto d : dependencies) {
            prereq[d[1]-1] |= 1 << (d[0]-1);
        }
        vector<int> set_pre(1 << n, 0);
        vector<int> valid(1 << n, 0);
        for (int mask = 0; mask < (1<<n); mask++) {
            if (__builtin_popcount(mask) <= k) {
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) { // the course is in the mask
                        set_pre[mask] |= prereq[i];
                    }
                }
                valid[mask] = ((mask & set_pre[mask]) == 0);
            }
        }
        
        vector<int> dp(1<<n, 15);
        dp[0] = 0;
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int subset = mask; subset; subset = (subset-1)&mask) {
                if (valid[subset] && ((mask&set_pre[subset]) == set_pre[subset])) {
                    dp[mask] = min(dp[mask], dp[mask ^ subset] + 1);
                }
            }
        }
        return dp[(1<<n)-1];
    }
};