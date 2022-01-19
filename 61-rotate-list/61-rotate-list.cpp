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
    
    ListNode* rotate(ListNode *head) {
        ListNode *prev = nullptr, *p = head;
        while(p->next != nullptr) {
            prev = p;
            p = p->next;
        }
        prev->next = nullptr;
        p->next = head;
        return p;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        int c = 0;
        ListNode *p = head;
        while(p != nullptr) {
            c++;
            p = p->next;
        }
        k = k % c;
        while(k>0) {
            head = rotate(head);
            k--;
        }
        return head;
    }
};