// LeetCode 56: Merge Intervals

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        int begin = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > end) {
                ret.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            }
            else if (intervals[i][1] > end) end = intervals[i][1];
        }
        ret.push_back({begin, end});
        return ret;
    }
};