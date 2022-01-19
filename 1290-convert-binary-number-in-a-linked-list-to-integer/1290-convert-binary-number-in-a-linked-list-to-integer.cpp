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
    int getDecimalValue(ListNode* head) {
        int cnt = 0, res = 0;
        ListNode *p = head;
        while(p != nullptr) {
            cnt++;
            p = p->next;
        }
        cnt--;
        p = head;
        while(p != nullptr) {
            res += p->val * pow(2, cnt);
            cnt--;
            p = p->next;
        }
        return res;
    }
};