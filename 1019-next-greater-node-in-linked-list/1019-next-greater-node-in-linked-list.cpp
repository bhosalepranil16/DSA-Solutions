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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr, res;
        while(head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        stack<int> st;
        int n = arr.size();
        st.push(arr[n-1]);
        res.push_back(0);
        for(int i=n-2;i>=0;i--) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                res.push_back(0);
            } else {
                res.push_back(st.top());
            }
            st.push(arr[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};