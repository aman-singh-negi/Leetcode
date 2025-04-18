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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* temp=head;
        ListNode* front=NULL;
        ListNode* back=NULL;
        while(temp!=NULL)
        {
            front=temp->next;
            temp->next=back;
            back=temp;
            temp=front;
        }
        return back;
    }
};