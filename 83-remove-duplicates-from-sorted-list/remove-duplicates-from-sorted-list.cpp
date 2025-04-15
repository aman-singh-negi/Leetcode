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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)return head;
        ListNode* temp=head->next;
        ListNode* back=head;
        while(temp!=NULL)
        {
            if(temp->val == back->val)
            {
                back->next=temp->next;
                delete temp;
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