// LeetCode 1493: Longest Subarray of 1's After Deleting One Element

#include <vector>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        if (N <= 1) return 0;
        int count1 = 0;
        int prevcount = 0;
        int longest = 0;
        bool has0 = false;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 1) {
                count1 ++;
            }
            else {
                has0 = true;
                longest = max(longest, prevcount+count1);
                prevcount = count1;
                count1 = 0;
                if (i >= 1 && nums[i-1] == 0) prevcount = 0;
            }
        }
        if (nums[N-1] == 1) longest = max(longest, prevcount+count1);
        if (!has0) return N-1;
        return longest;
    }
};