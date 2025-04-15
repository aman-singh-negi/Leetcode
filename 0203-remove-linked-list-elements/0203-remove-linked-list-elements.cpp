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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val)
        {
            head=head->next;
        }
        ListNode* back=head;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val==val)
            {
                ListNode* del=temp;
                back->next=temp->next;
                delete del;
                temp=back->next;
            }
            else 
            {
                back=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};