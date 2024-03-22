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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *nextNode = head;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        };
        return prev;
    };
    
    bool isPalindrome(ListNode *head) {
        ListNode *dummy = new ListNode(69, head), *slow = dummy, *fast = dummy;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        fast = head, slow = reverse(slow);
        while (fast && slow) {
            if (slow->val != fast->val) {
                return false;    
            };
            slow = slow->next;
            fast = fast->next;
        };        
        return true;
    };
};