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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> s1, s2;
        while(l1 != nullptr) {
            s1.push(l1);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            s2.push(l2);
            l2 = l2->next;
        }
        
        ListNode *head = nullptr;
        int carry = 0, sum = 0;
        while(!s1.empty() && !s2.empty()) {
            sum = s1.top()->val + s2.top()->val + carry;
            carry = sum / 10;
            if(head == nullptr) {
                head = new ListNode(sum % 10);
            } else {
                ListNode *q = new ListNode(sum % 10);
                q->next = head;
                head = q;
            }
            s1.pop();
            s2.pop();
        }
        
        while(!s1.empty()) {
            sum = s1.top()->val + carry;
            carry = sum / 10;
            if(head == nullptr) {
                head = new ListNode(sum % 10);
            } else {
                ListNode *q = new ListNode(sum % 10);
                q->next = head;
                head = q;
            }
            s1.pop();
        }
        
        while(!s2.empty()) {
            sum = s2.top()->val + carry;
            carry = sum / 10;
            if(head == nullptr) {
                head = new ListNode(sum % 10);
            } else {
                ListNode *q = new ListNode(sum % 10);
                q->next = head;
                head = q;
            }
            s2.pop();
        }
        if(carry) {
            if(head == nullptr) {
                head = new ListNode(carry);
            } else {
                ListNode *q = new ListNode(carry);
                q->next = head;
                head = q;
            }
        }
        return head;
    }
};