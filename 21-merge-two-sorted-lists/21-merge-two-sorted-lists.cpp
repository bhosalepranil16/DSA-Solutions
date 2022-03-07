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
    void add(vector<ListNode*> &arr, ListNode *q) {
        if(arr[0] == NULL) {
            arr[0] = q;
            arr[1] = q;
        } else {
            arr[1]->next = q;
            arr[1] = arr[1]->next;
        }
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr) {
            return nullptr;
        } else if(l1 == nullptr) {
            return l2;
        } else if(l2 == nullptr) {
            return l1;
        }
        vector<ListNode*> ans(2, nullptr);
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                add(ans, l1);
                l1 = l1->next;
            } else {
                add(ans, l2);
                l2 = l2->next;
            }
        }
        while(l1 != nullptr) {
            add(ans, l1);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            add(ans, l2);
            l2 = l2->next;
        }
        return ans[0];
    }
};