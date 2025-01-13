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
    ListNode* merge(ListNode* head1,ListNode* head2)
    {
        ListNode* newDummy=new ListNode(-1);
        ListNode* mover=newDummy;
        while(head1!=NULL && head2!=NULL)
        {
            if (head1->val < head2->val) {
                mover->next = head1;
                head1 = head1->next;
            } else {
                mover->next = head2;
                head2 = head2->next;
            }
            mover = mover->next;
        }
        if(head1!=NULL)mover->next=head1;
        if(head2!=NULL)mover->next=head2;
        return newDummy->next;
    }
    ListNode* findmid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if (prev != NULL) prev->next = NULL;
        return slow;
    }
    ListNode* mergeSort(ListNode* head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode* mid=findmid(head);
        ListNode* left=mergeSort(head);
        ListNode* right=mergeSort(mid);
        return merge(left,right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};