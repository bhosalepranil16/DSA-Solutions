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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        ListNode *headOdd = head, *headEven = head->next, *tailOdd = head, *tailEven = head->next;
        bool isOdd = true;
        head = head->next->next;
        while(head != nullptr) {
            if(isOdd) {
                tailOdd->next = head;
                tailOdd = tailOdd->next;
            } else {
                tailEven->next = head;
                tailEven = tailOdd->next;
            }
            head = head->next;
            isOdd = !isOdd;
        }
        tailEven->next = nullptr;
        tailOdd->next = headEven;
        return headOdd;
    }
};