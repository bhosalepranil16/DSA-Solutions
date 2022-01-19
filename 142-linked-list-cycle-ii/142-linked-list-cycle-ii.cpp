/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        bool flag = false;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                flag = true;
                break;
            }
        }
        if(!flag)
            return NULL;
        fast = head;
        while(true) {
            if(slow == fast) {
                return slow;
            }
            if(slow->next == fast->next) {
                return slow->next;
            }
            slow = slow->next;
            fast = fast->next;
        }
    }
};