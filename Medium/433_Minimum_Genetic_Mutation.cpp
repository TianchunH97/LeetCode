// LeetCode 433: Minimum Genetic Mutation

#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict;
        unordered_set<string> visited;
        for (string s : bank) {
            dict.insert(s);
        }
        if (!dict.count(end)) return -1;
        vector<string> choices = {"A", "C", "G", "T"};
        queue<string> q;
        q.push(start);
        visited.insert(start);
        int count = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string str = q.front();
                q.pop();
                if (str == end) return count;
                for (int j = 0; j < str.length(); j++) {
                    for (string ch : choices) {
                        string tmp = str;
                        tmp = tmp.replace(j,1,ch);
                        if (!visited.count(tmp) && dict.count(tmp)) {
                            q.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
            count ++;
        }
        return -1;
    }
};