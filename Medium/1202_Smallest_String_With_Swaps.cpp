// LeetCode 1202: Smallest String With Swaps

#include <vector>
#include <string>

using namespace std;

class Solution {
    int pre[100001];
    int find(int root) {
        if (root == pre[root]) return root;
        int son = root;
        while (root != pre[root]) {
            root = pre[root];
        }
        int tmp;
        while (son != root) {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if (pairs.size() == 0) return s;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            pre[i] = i;
        }
        for (auto p : pairs) {
            pre[find(p[0])] = find(p[1]);
        }
        vector<vector<char>> groups(len);
        for (int i = 0; i < len; i++) {
            groups[find(i)].push_back(s[i]);
        }
        for (int i = 0; i < groups.size(); i++) {
            if (groups[i].size() > 1) sort(groups[i].rbegin(), groups[i].rend());
        }
        string ret = "";
        for (int i = 0; i < len; i++) {
            ret += groups[pre[i]].back();
            groups[pre[i]].pop_back();
        }
        return ret;
    }
};