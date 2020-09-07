#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        vector<Node*> nodes;
        unordered_map<Node*, int> map;
        Node* tmp = head;
        while (tmp) {
            nodes.push_back(new Node(tmp->val));
            int size = nodes.size();
            map[tmp] = size-1;
            if (size > 1) nodes[size-2]->next = nodes[size-1];
            tmp = tmp->next;
        }
        tmp = head;
        int i = 0;
        while (tmp) {
            if (!tmp->random) nodes[i]->random = nullptr;
            else nodes[i]->random = nodes[map[tmp->random]];
            tmp = tmp->next;
            i++;
        }
        return nodes[0];
    }
};