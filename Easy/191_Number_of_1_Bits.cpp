// LeetCode 191: Number of 1 Bits

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);
    }
};