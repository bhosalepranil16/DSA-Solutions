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
    ListNode* deleteMiddle(ListNode* head) {
        
        int c = 0;
        ListNode *p = head;
        while(p != nullptr) {
            p = p->next;
            c++;
        }
        
        if(c == 1) {
            delete head;
            return nullptr;
        } else {
            p = head;
            for(int i=1;i<c/2;i++) {
                p = p->next;
            }
            ListNode *q = p->next;
            p->next = q->next;
            delete q;
            return head;
        }
    }
};