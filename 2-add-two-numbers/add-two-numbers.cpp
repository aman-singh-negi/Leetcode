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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=l1;
        ListNode* back=l1;
        while(l1!=NULL && l2!=NULL)
        {
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
            l1->val=sum;
            back=l1;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL)
        {
            int sum=l1->val+carry;
            carry=sum/10;
            sum=sum%10;
            l1->val=sum;
            back=l1;
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=carry+l2->val;
            carry=sum/10;
            sum=sum%10;
            ListNode* temp=new ListNode(sum);
            back->next=temp;
            back=temp;
            l2=l2->next;
        }
        while(carry)
        {
            int sum=carry%10;
            carry=carry/10;
            ListNode* temp=new ListNode(sum);
            back->next=temp;
            back=temp;
        }
        return head;
    }
};