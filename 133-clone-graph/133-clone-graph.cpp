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
    void dfs(Node* curr, Node* node, vector<Node*> &vis)
    {
        vis[node->val] = node;
        for(auto nei: curr->neighbors )
        {
            if(vis[nei->val] == NULL)
            {
                Node* newnode = new Node(nei->val);
                (node->neighbors).push_back(newnode);
                dfs(nei, newnode, vis);
            }
            else
            {
                (node->neighbors).push_back(vis[nei->val]);
            }
        }
        
        
    }
    
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        // to store wether or not that particular node is created
        vector<Node*> vis(1000, NULL);
        
        Node *copy = new Node(node->val);
        vis[node->val] = copy;
        
        for(auto nei: node->neighbors)
        {
            if(vis[nei->val] == NULL)
            {
                Node* newnode = new Node(nei->val);
                // vis[nei->val] = nei;
                (copy->neighbors).push_back(newnode);
                dfs(nei, newnode, vis);
            }
            else
            {
                (copy->neighbors).push_back(vis[nei->val]);
            }
        }
        
        return copy;
        
    }
};