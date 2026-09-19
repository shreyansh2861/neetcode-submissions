class LRUCache {
public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node(int k, int v): key(k), val(v), next(nullptr) {}
    };

    int c,cnt;
    Node *head = new Node(-1,-1);

    LRUCache(int capacity) {
        cnt=0;
        c = capacity;
    }
    
    int get(int key) {
        Node *temp = head;
        int value;
        while(temp->next){
            if(temp->next->key==key){
                value = temp->next->val;
                break;
            }
            temp=temp->next;
        }

        if(temp->next && temp->next->key==key){
            Node *n = temp->next;
            temp->next = temp->next->next;
            while(temp->next){
                temp=temp->next;
            }
            temp->next = n;
            n->next=nullptr;

            return value;
        }
        return -1;
        

    }
    
    void put(int key, int value) {
        int there = get(key);
        if(cnt==c && there==-1){
            head->next = head->next->next;
            cnt--;
        }
        Node *temp = head;
        if(there!=-1){
            while(temp->next){
                if(temp->next->key==key){
                    temp->next->val = value;
                    return;
                }
                temp=temp->next;
            }
        }

        while(temp->next){
            temp=temp->next;
        }
        
        Node *n = new Node(key, value);

        temp->next = n;
        cnt++;
    }
};
