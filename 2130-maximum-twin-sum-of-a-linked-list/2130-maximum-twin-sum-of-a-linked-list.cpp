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
    int pairSum(ListNode* head) {
        stack<ListNode*> st;
        ListNode *p = head;
        while(p != nullptr) {
            st.push(p);
            p = p->next;
        }
        p = head;
        int res = INT_MIN;
        while(p != nullptr) {
            res = max(res, p->val+st.top()->val);
            p=p->next;
            st.pop();
        }
        return res;
    }
};