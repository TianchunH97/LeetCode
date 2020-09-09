// LeetCode 1488: Avoid Flood in The City

#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> dry;
        int N = rains.size();
        unordered_map<int, int> lakes;
        vector<int> ret(N, 1);
        for (int i = 0; i < N; i++) {
            if (rains[i] > 0) {
                ret[i] = -1;
                if (!lakes.count(rains[i])) lakes[rains[i]] = i;
                else {
                    auto it = dry.upper_bound(lakes[rains[i]]);
                    if (it == dry.end()) return {};
                    else {
                        ret[*it] = rains[i];
                        dry.erase(it);
                        lakes[rains[i]] = i;
                    }
                }
            }
            else dry.insert(i);
        }
        return ret;
    }
};