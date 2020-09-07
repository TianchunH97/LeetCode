// LeetCode 721: Accounts Merge

#include <map>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    int find(int root, vector<int> &pre) {
        if (root == pre[root]) return root;
        int son = root;
        int tmp;
        while (root != pre[root]) {
            root = pre[root];
        }
        while (son != root) {
            tmp = pre[son];
            pre[son] = root;
            son = tmp;
        }
        return root;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emails;
        int t = 0;
        for (auto vec : accounts) {
            for (int i = 1; i < vec.size(); i++) {
                if (!emails.count(vec[i])) {
                    emails[vec[i]] = t;
                    t++;
                }
            }
        }
        vector<int> pre(emails.size());
        for (int i = 0; i < pre.size(); i++) {
            pre[i] = i;
        }
        for (auto vec : accounts) {
            for (int i = 2; i < vec.size(); i++) {
                pre[find(emails[vec[i]], pre)] = find(emails[vec[1]], pre); 
            }
        }
        vector<vector<string>> ret;
        unordered_map<int, int> roots;
        for (int i = 0; i < accounts.size(); i++) {
            int root = find(emails[accounts[i][1]], pre);
            if (!roots.count(root)) {
                roots[root] =ret.size();
                ret.push_back({accounts[i][0]});
            }
        }
        for (auto it=emails.begin(); it!=emails.end(); it++) {
            ret[roots[find(it->second, pre)]].push_back(it->first);
        }
        return ret;
    }
};