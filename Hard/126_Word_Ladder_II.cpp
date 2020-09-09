// LeetCode 126: Word Ladder II

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<int>> q;
        unordered_map<string, int> wordDict;
        unordered_set<int> visited;
        vector<vector<string>> ret;
        vector<vector<int>> tmp_ret;
        for (int i = 0; i < wordList.size(); i++) {
            wordDict[wordList[i]] = i;
        }
        if (!wordDict.count(endWord)) return {};
        if (!wordDict.count(beginWord)) {
            wordList.push_back(beginWord);
            wordDict[beginWord] = wordList.size()-1;
        }
        q.push({wordDict[beginWord]});
        visited.insert(wordDict[beginWord]);
        while (!q.empty()) {
            int size = q.size();
            vector<int> newwords;
            for (int i = 0; i < size; i++) {
                vector<int> words = q.front();
                q.pop();
                string curr = wordList[words.back()];
                for (int j = 0; j < curr.length(); j++) {
                    for (int k = 0; k < 26; k++) {
                        string tmp = curr;
                        tmp[j] = 'a'+k;
                        if (tmp == endWord) {
                            words.push_back(wordDict[tmp]);
                            tmp_ret.push_back(words);
                            words.pop_back();
                        }
                        else if (wordDict.count(tmp) && !visited.count(wordDict[tmp])) {
                            words.push_back(wordDict[tmp]);
                            q.push(words);
                            words.pop_back();
                            newwords.push_back(wordDict[tmp]);
                        }
                    }
                }
            }
            if (tmp_ret.size() > 0) break;
            for (int w : newwords) {
                visited.insert(w);
            }
        }
        for (const auto& vec : tmp_ret) {
            vector<string> str_vec;
            for (int i : vec) {
                str_vec.push_back(wordList[i]);
            }
            ret.push_back(str_vec);
        }
        return ret;
    }
};