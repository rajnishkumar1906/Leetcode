/*
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
*/

class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;

        // If thee node is alreay present in mp then return that simply
        if(mp.find(node)!=mp.end())
        {
            return mp[node];
        }

        // Creating new key to store in clone graoh map
        Node* newNode = new Node(node->val);
        mp[node] = newNode;     //Clone this node

        for(auto neighbour : node->neighbors)
        {
            mp[node]->neighbors.push_back(cloneGraph(neighbour));
        }

        return newNode;
    }
};