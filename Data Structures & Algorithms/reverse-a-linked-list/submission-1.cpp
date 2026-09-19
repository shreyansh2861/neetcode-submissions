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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode *t1, *t2, *t3;
        t1=head;
        t2=t1->next;
        t3=t2->next;

        head->next=nullptr;

        while(t3){
            t2->next=t1;
            t1=t2;
            t2=t3;
            t3=t3->next;
        }

        t2->next=t1;
        head=t2;
        return head;
    }
};
