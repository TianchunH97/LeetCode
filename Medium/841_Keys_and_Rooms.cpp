// LeetCode 841: Keys and Rooms

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), 0);
        visited[0] = 1;
        stack<int> st;
        for (int k : rooms[0]) {
            st.push(k);
        }
        int t;
        while (!st.empty()) {
            t = st.top();
            st.pop();
            if (!visited[t]) {
                visited[t] = 1;
                for (int k : rooms[t]) {
                    st.push(k);
                }
            }
        }
        for (bool b : visited) {
            if (b == 0) return false;
        }
        return true;
    }
};