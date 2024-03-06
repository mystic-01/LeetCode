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
    bool hasCycle(ListNode *head) {
        ListNode *dummy = new ListNode(69), *slow = dummy, *fast = dummy;
        dummy->next = head;
        
        while (slow && fast && fast->next) {
            slow = slow->next, fast = fast->next->next;             
            if (slow == fast) return true;
        };
        return false;
    };
};