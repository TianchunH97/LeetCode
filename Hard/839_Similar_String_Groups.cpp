// LeetCode 839: Similar String Groups

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    int pre[2000];
    int find(int root) {
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
    
    bool isSimilar(string str1, string str2) {
        if (str1.length() != str2.length()) return false;
        int diff = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return true;
    }
public:
    int numSimilarGroups(vector<string>& A) {
        int diff = 0;
        for (int i = 0; i < A[0].length(); i++) {
            if (A[0][i] != A[0][0]) diff += 1;;
        }
        if (diff < 2) return 1;
        for (int i = 0; i < A.size(); i++) {
            pre[i] = i;
        }
        for (int i = 0; i < A.size()-1; i++) {
            for (int j = i+1; j < A.size(); j++) {
                if (isSimilar(A[i], A[j])) pre[find(i)] = find(j);
            }
        }
        unordered_set<int> count;
        for (int i = 0; i < A.size(); i++) {
            count.insert(find(i));
        }
        return count.size();
    }
};