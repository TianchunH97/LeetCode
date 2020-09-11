// LeetCode 169: Majority Element

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (int num : nums) {
            if (counter.count(num)) counter[num] += 1;
            else counter[num] = 1;
            if (counter[num] > n/2) return num;
        }
        return 0;
    }
};