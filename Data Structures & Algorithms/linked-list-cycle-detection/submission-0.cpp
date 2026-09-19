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
    bool hasCycle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return false;
        }
        ListNode *t1,*t2;
        t1=head->next;
        t2=head->next->next;

        while(t2 && t2->next){
            if(t1==t2){
                return true;
            }
            t1=t1->next;
            t2=t2->next->next;
        }

        return false;
    }
};
