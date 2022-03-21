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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        else if(head->next == nullptr)
            return head;
        else {
            ListNode *h = head;
            ListNode *p = head;
            ListNode *q = head->next;
            while(true) {
                if(p == nullptr || q == nullptr)
                    break;
                swap(p->val, q->val);
                if(p->next != nullptr && q->next != nullptr) {
                    p = p->next->next;
                    q = q->next->next;
                } else {
                    break;
                }
            }
            return head;
        }
    }
};