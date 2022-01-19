class Node {
    public:
    int val;
    Node *next, *prev;
    Node() {
        val = 0;
        next = prev = NULL;
    }
    Node(int x) {
        val = x;
        next = prev = NULL;
    }
};

class MyLinkedList {
public:
    Node *head;
    MyLinkedList() {
        head = NULL;
    }
    
    int count() {
        int cnt = 0;
        Node *p = head;
        while(p != NULL) {
            cnt++;
            p = p->next;
        }
        return cnt;
    }
    
    int get(int index) {
        int c = count();
        if(index < 0 || index >= c) {
            return -1;
        }
        Node *p = head;
        for(int i=0;i<index;i++) {
            p = p->next;
        }
        return p->val;
    }
    
    void addAtHead(int val) {
        Node *q = new Node(val);
        if(head == NULL) {
            head = q;
        } else {
            q->next = head;
            head->prev = q;
            head = q;
        }
    }
    
    void addAtTail(int val) {
        Node *q = new Node(val);
        if(head == NULL) {
            head = q;
        } else {
            Node *p = head;
            while(p->next != NULL) {
                p = p->next;
            }
            q->prev = p;
            p->next = q;
        }
    }
    
    void addAtIndex(int index, int val) {
        int c = count();
        if(index < 0 || index > c) {
            return;
        }
        if(index == 0) {
            addAtHead(val);
        } else if(index == c) {
            addAtTail(val);
        } else {
            Node *p = head;
            for(int i=0;i<index-1;i++) {
                p = p->next;
            }
            Node *q = new Node(val);
            q->next = p->next;
            q->prev = p;
            p->next->prev = q;
            p->next = q;
        }
    }
    
    void deleteAtHead() {
        if(head == NULL) {
            return;
        } else if(head->next == NULL) {
          delete head;
            head = NULL;
        } else {
            Node *q = head;
            head = head->next;
            head->prev = nullptr;
            delete q;
        }
    }
    
    
    void deleteAtIndex(int index) {
        int c = count();
        if(index >= c) {
            return;
        } else if(index == 0) {
            deleteAtHead();
        } else if(index == c-1) {
          Node *p = head, *q = NULL;
            while(p->next != NULL) {
                q = p;
                p=p->next;
            }
            q->next = NULL;
            delete p;
        } else {
            Node *p = head;
            for(int i=1;i<index;i++) {
                p = p->next;
            }
            Node *q = p->next;
            p->next = q->next;
            q->next->prev = p;
            delete q;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */