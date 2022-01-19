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
        ListNode* slow = head, * fast = head;
        if (!head || !head->next) return false;
        while (1) {
            slow = slow->next;            
            if (fast->next == nullptr) return false;
            fast = fast->next->next;  
            if (slow == nullptr || fast == nullptr) return false;
            if (slow == fast) return true;
        };
        return false;
    };
};