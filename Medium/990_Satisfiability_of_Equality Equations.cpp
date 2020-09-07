// LeetCode 990: Satisfiability of Equality Equations

#include <vector>
#include <string>

using namespace std;

class Solution {
    int pre[26];
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
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) {
            pre[i] = i;
        }
        for (string eq : equations) {
            if (eq[1] == '=' && eq[0] != eq[3]) pre[find(eq[0]-'a')] = find(eq[3]-'a'); 
        }
        for (string eq : equations) {
            if (eq[1] == '!' && find(eq[0]-'a') == find(eq[3]-'a')) return false;
        }
        return true;
    }
};