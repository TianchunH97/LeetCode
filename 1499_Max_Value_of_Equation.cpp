// Leetcode 1499: Max Value of Equation

#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<int> dq;
        int ret = INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            while (!dq.empty() && points[i][0]-points[dq.front()][0] > k) {
                 dq.pop_front();
            }
            if (!dq.empty()) ret = max(ret, points[dq.front()][1]-points[dq.front()][0]+points[i][0]+points[i][1]);
            while (!dq.empty() && points[i][1]-points[i][0] > points[dq.back()][1]-points[dq.back()][0]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ret;
    }
};