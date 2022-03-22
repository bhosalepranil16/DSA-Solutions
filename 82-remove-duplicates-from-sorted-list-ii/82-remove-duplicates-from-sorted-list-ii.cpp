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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *sentinel = new ListNode(-101, head);
        ListNode *pred = sentinel;
        
        while(head != nullptr) {
            
            if(head->next != nullptr && head->val == head->next->val) {
                
                while(head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                
                pred->next = head->next;
                
            } else {
                pred = pred->next;
            }
            head = head->next;
        }
        
        return sentinel->next;
        
    }
};