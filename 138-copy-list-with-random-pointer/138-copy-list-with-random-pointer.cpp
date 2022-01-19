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
        unordered_map<Node*, Node*> hash;
        
        Node *p = head;
        while(p != NULL) {
            hash[p] = new Node(p->val);
            p = p->next;
        }
        
        Node *res = NULL;
        
        p = head;
        while(p != NULL) {
            Node *curr = hash[p];
            curr->next = hash[p->next];
            curr->random = hash[p->random];
            if(p == head) {
                res = curr;
            }
            p = p->next;
        }
        
        return res;
        
    }
};