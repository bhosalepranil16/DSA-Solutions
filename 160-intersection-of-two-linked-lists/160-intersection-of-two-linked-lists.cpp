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
    int count(ListNode *head) {
        int cnt = 0;
        while(head != NULL) {
            cnt++;
            head = head->next;
        }
        return cnt;
    } 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) {
            return NULL;
        }
        int cnt1 = count(headA), cnt2 = count(headB);
        ListNode *maxHead, *minHead;
        int maxCnt, minCnt;
        if(cnt1 < cnt2) {
            minHead = headA;
            maxHead = headB;
            minCnt = cnt1;
            maxCnt = cnt2;
        } else {
            minHead = headB;
            maxHead = headA;
            minCnt = cnt2;
            maxCnt = cnt1;
        }
        for(int i=0;i<(maxCnt - minCnt);i++) {
            maxHead = maxHead->next;
        }
        // cout << minHead->val << " " << maxHead->val << "\n";
        while(minHead != NULL && maxHead != NULL) {
            if(minHead == maxHead) {
                return minHead;
            }
            minHead = minHead->next;
            maxHead = maxHead->next;
        }
        return NULL;
    }
};