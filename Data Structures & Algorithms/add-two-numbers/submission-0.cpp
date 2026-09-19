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
        ListNode *temp = new ListNode(0), *ans = temp;
        int carry=0;

        while(l1 || l2){
            if(l1==nullptr){
                int next = l2->val + carry;
                temp->next = new ListNode(next%10);
                carry = next/10;
                l2 = l2->next;
            }
            else if(l2==nullptr){
                int next = l1->val + carry;
                temp->next = new ListNode(next%10);
                carry = next/10;
                l1 = l1->next;
            }
            else{
                int next = l1->val + l2->val + carry;
                temp->next = new ListNode(next%10);
                carry = next/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            temp=temp->next;
        }

        if(carry){
            temp->next = new ListNode(carry);
        }

        return ans->next;

    }
};
