// LeetCode 997: Find the Town Judge

#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trust_count(N+1, 0);
        vector<int> trusted(N+1, 0);
        for (auto t : trust) {
            trust_count[t[0]] += 1;
            trusted[t[1]] += 1;
        }
        int ret = -1;
        for (int i = 1; i <= N; i++) {
            if (trust_count[i] == 0 && trusted[i] == N-1) {
                if (ret != -1) return -1;
                else ret = i;
            }
        }
        return ret;
    }
};