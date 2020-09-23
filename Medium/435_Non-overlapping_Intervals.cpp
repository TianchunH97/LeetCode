// LeetCode 435: Non-overlapping Intervals

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
            else end = min(end, intervals[i][1]);
        }
        count++;
        return intervals.size()-count;
    }
};