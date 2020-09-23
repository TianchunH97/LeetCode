// LeetCode 452: Minimum Number of Arrows to Burst Balloons

#include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end());
        int minend = points[0][1];
        int arrow = 0;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > minend) {
                arrow++;
                minend = points[i][1];
            }
            else minend = min(minend, points[i][1]);
        }
        arrow++;
        return arrow;
    }
};