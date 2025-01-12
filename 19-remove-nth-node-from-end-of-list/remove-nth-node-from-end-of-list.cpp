/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int N) {
        if(head==NULL)return NULL;
        ListNode* fast=head;
        while(N-- && fast!=NULL)
        {
            fast=fast->next;
        }
        ListNode* slow=head;
        ListNode* prev=head;
        while(fast!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        if(slow==head)
        {
            head=head->next;
            delete slow;
        }
        else
        {
            prev->next=slow->next;
            slow->next=NULL;
            delete slow;
        }
        return head;
    }
};