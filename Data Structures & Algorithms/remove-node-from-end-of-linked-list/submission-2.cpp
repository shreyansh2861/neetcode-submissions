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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *t2=head,*t1=dummy;

        while(n>0){
            t2=t2->next;
            n--;
        }

        while(t2!=nullptr){
            t1=t1->next;
            t2=t2->next;
        }

        t1->next=t1->next->next;

        return dummy->next;
    }
};
