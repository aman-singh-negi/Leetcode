/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int flag=0;
        while(tempA!=NULL || tempB!=NULL)
        {
            if(tempA==tempB)return tempA;
            tempA=tempA->next;
            tempB=tempB->next;
            if(tempA==NULL && flag<2)
            {
                tempA=headB;
                flag++;
            }
            if(tempB==NULL && flag<2)
            {
                tempB=headA;
                flag++;
            }
        }
        return NULL;
    }
};