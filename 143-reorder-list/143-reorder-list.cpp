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
    void reorderList(ListNode* head) {
        int c = 0;
        stack<ListNode*> st;
        ListNode *p = head;
        while(p != nullptr) {
            c++;
            st.push(p);
            p = p->next;
        }
        p = head->next;
        ListNode *tail = head;
        bool isStack = true;
        for(int i=1;i<c;i++) {
            if(isStack) {
                tail->next = st.top();
                st.pop();
            } else {
                tail->next = p;
                p = p->next;
            }
            tail = tail->next;
            isStack = !isStack;
        }
        tail->next = nullptr;
    }
};