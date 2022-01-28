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
    
    ListNode* reverse(ListNode *head, int k, int c) {
        // base case
        if(head == nullptr) {
            return nullptr;
        }
        
        if(k > c) {
            return head;
        }
        
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        int count = 0;
        while(curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != nullptr) {
            head->next = reverse(next, k, c-k);
        }
        return prev;
    }
    
    int countNodes(ListNode *head) {
        int c = 0;
        while(head != nullptr) {
            c++;
            head = head->next;
        }
        return c;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int c = countNodes(head);
        return reverse(head, k, c);
    }
};