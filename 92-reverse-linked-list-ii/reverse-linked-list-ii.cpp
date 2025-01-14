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
    ListNode* reverseLL(ListNode* head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode* newHead=reverseLL(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode* lefty=NULL;
        ListNode* righty=NULL;     
        int cnt=1;
        ListNode* prev=head;
        ListNode* temp=head;
        while(temp)       
        {
            if(cnt==left)
            {
                lefty= temp;
            }
            if(lefty==NULL)
            {
                prev=temp;
            }
            if(cnt==right)
            {
                righty=temp;
            }
            cnt++;
            temp=temp->next;
        }
        ListNode* back=righty->next;
        righty->next=NULL;
        if(lefty==head)
        {
            head=reverseLL(lefty);
            prev=head;
        }
        else
        {
            prev->next=reverseLL(lefty);
        }
        while(prev->next!=NULL)prev=prev->next;
        prev->next=back;
        return head;
    }
};