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
    Node* solve(Node* node,unordered_map<Node*,Node*>&mpp)
    {
        if(node==NULL)
        {
            return NULL;
        }
        if(mpp.find(node)!=mpp.end())
        {
            return mpp[node];
        }
        Node* clone=new Node(node->val);
        mpp[node]=clone;
        for(int i=0;i<node->neighbors.size();i++)
        {
            clone->neighbors.push_back(solve(node->neighbors[i],mpp));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mpp;
        return solve(node,mpp);
    }
};