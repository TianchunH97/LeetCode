// LeetCode 3: Longest Substring Without Repeating Characters

#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        int len = 0;
        unordered_map<char, int> dict;
        for (int i = 0; i < s.length(); i++) {
            if (!dict.count(s[i]) || dict[s[i]] < start) {
                dict[s[i]] = i;
                len = max(len, i-start+1);
            }
            else {
                start = dict[s[i]]+1;
                dict[s[i]] = i;
                len = max(len, i-start+1);
            }
        }
        return len;
    }
};