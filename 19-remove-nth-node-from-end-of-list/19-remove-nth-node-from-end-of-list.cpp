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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = -1;
        ListNode * dummy = new ListNode(69), * temp = dummy;
        dummy->next = head;
        while (temp) {
            temp = temp->next;
            count++;  
        };
        temp = dummy;
        while (temp) {
            if (count == n) temp->next = temp->next->next;
            count--;
            temp = temp->next;
        };
        return dummy->next;
    };
};