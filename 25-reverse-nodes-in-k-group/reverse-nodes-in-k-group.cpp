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
class Solution 
{
    private:
        ListNode* reverseLL(ListNode* temp)
        {
            ListNode* front=nullptr;
            ListNode* back=nullptr;
            ListNode* mover=temp;
            while(mover!=nullptr)
            {
                front=mover->next;
                mover->next=back;
                back=mover;
                mover=front;
            }
            return back;
        }
        ListNode* kthNode(ListNode* temp,int k)
        {
            while(k && temp)
            {
                temp=temp->next;
                k--;
                if(k==0 || k==1)break;
            }
            return temp;
        }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head,*nextNode,*backNode;
        int flag=0;
        if(k==1)return head;
        while(temp!=nullptr)
        {
            ListNode* kth=kthNode(temp,k);
            if(kth==nullptr)
            {
                backNode->next=temp;
                break;
            }
            nextNode=kth->next;
            kth->next=nullptr;
            ListNode* newHead=reverseLL(temp);
            if(flag==0)
            {
                head=newHead;
                flag=1;
            }
            else{
                backNode->next=newHead;
            }
            backNode=temp;
            temp=nextNode;
        }
        return head;
    }
};