// LeetCode 1498: Number of Subsequences That Satisty the Given Sum Condition

#include <vector>

using namespace std;

class Solution { 
public:
    int numSubseq(vector<int>& nums, int target) {
        long count = 0;
        const long long mod = 1000000007;
        vector<long long> pow2(nums.size());
        pow2[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            pow2[i] = pow2[i-1]*2 % mod;
        }
        sort(nums.begin(), nums.end());
        if (nums.back()*2 <= target) return pow(2,nums.size())-1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]*2 > target) break;
            auto it = upper_bound(nums.begin(), nums.end(), target-nums[i]);
            int j = it-nums.begin()-1;
            long long p = pow2[j-i];
            count = (count + p) % mod;
        }
        return count;
    }
};