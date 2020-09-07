// LeetCode 1497: Check If Array Pairs Are Divisible by k

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> dict;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = arr[i]%k;
            if (arr[i] < 0) arr[i] += k;
            if (arr[i] == 0) {
                if (dict.count(0)) dict.erase(0);
                else dict[0] = 1;
            }
            else {
                if (dict.count(arr[i])) {
                    dict[arr[i]] -= 1;
                    if (dict[arr[i]] == 0) dict.erase(arr[i]);
                }
                else if (dict.count(k-arr[i])) dict[k-arr[i]] += 1;
                else dict[k-arr[i]] = 1;
            }
        }
        return dict.size()==0;
    }
};