/*
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
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mpp;
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* t=new Node(temp->val);
            mpp[temp]=t;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL)
        {
            Node* copy=mpp[temp];
            copy->next=mpp[temp->next];
            copy->random=mpp[temp->random];
            temp=temp->next;
        }
        return mpp[head];
    }
};