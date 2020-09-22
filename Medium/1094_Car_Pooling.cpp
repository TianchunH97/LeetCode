// LeetCode 1094: Car Pooling

#include <vector>
#include <queue>

using namespace std;

class Solution {
    typedef pair<int, int> PII;
    struct cmp
    {
        bool operator() (const vector<int>& A, const vector<int>& B) {
            return A[1] < B[1];
        }
    };
    
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int N = trips.size();
        if (N == 0) return true;
        sort(trips.begin(), trips.end(), cmp());
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        pq.push({trips[0][2], trips[0][0]});
        int curr = trips[0][0];
        for (int i = 1; i < N; i++) {
            while (!pq.empty() && trips[i][1] >= pq.top().first) {
                curr -= pq.top().second;
                pq.pop();
            }
            pq.push({trips[i][2], trips[i][0]});
            curr += trips[i][0];
            if (curr > capacity) return false;
        }
        return true;
    }
};