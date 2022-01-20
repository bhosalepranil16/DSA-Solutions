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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p1 = list1;
        for(int i=1;i<a;i++) {
            p1 = p1->next;
        }
        ListNode *q1 = p1->next;
        for(int i=0;i<=(b-a);i++) {
            ListNode *q = q1;
            q1 = q1->next;
            delete q;
        }
        
        p1->next = list2;
        while(p1->next != NULL) {
            p1 = p1->next;
        }
        p1->next = q1;
        return list1;
    }
    
};