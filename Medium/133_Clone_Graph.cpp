// LeetCode 133: Clone Graph

#include <vector>
#include <stack>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        vector<Node*> nodes;
        for (int i = 0; i < 101; i++) {
            nodes.push_back(new Node(i));
        }
        Node* root = nodes[node->val];
        stack<Node*> st;
        st.push(node);
        vector<bool> visited(101, false);
        while (!st.empty()) {
            Node* curr = st.top();
            st.pop();
            if (visited[curr->val]) continue;
            visited[curr->val] = 1;
            Node* copy = nodes[curr->val];
            for (Node* n : curr->neighbors) {
                copy->neighbors.push_back(nodes[n->val]);
                st.push(n);
            }
        }
        return root;
    }
};