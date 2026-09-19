/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> cnt;
        Node* dynamic = new Node(0);
        Node *temp=head, *t=dynamic;
        while(temp){
            t->next = new Node(temp->val);
            t=t->next;
            cnt[temp]=t;
            temp=temp->next;
        }

        temp=head;

        while(temp){
            cnt[temp]->random=cnt[temp->random];
            temp=temp->next;
        }

        return dynamic->next;
    }
};
