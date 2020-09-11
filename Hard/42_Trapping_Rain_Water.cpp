// LeetCode 42: Trapping Rain Water

#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int N = height.size();
        if (N < 3) return 0;
        vector<int> leftmax(N, 0);
        vector<int> rightmax(N, 0);
        leftmax[0] = 0;
        for (int i = 1; i < N; i++) {
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }
        rightmax[N-1] = 0;
        for (int i = N-2; i >= 0; i--) {
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }
        int water = 0;
        for (int i = 1; i < N-1; i++) {
             water += max(0, min(leftmax[i], rightmax[i])-height[i]);
        }
        return water;
    }
};