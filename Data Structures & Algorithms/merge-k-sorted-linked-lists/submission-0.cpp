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
    ListNode* merge(ListNode* t1, ListNode* t2){
        ListNode *temp = new ListNode(0), *t=temp;

        while(t1 || t2){
            if(!t1){
                while(t2){
                    t->next=t2;
                    t=t->next;
                    t2=t2->next;
                }
            }
            if(!t2){
                while(t1){
                    t->next=t1;
                    t=t->next;
                    t1=t1->next;
                }
            }
            else{
                if(t1->val<=t2->val){
                    t->next=t1;
                    t1=t1->next;
                }
                else{
                    t->next=t2;
                    t2=t2->next;
                }

                t=t->next;
            }
        }

        return temp->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return nullptr;
        }
        else if(lists.size()==1){
            return lists[0];
        }
        for(int i=1;i<lists.size();i++){
            ListNode *tHead = merge(lists[i-1],lists[i]);
            lists[i] = tHead;
        }


        return lists[lists.size()-1];

    }
};
