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
    ListNode *reverse(ListNode * curr) {
        ListNode *prev = nullptr, *newNode = nullptr;
        while (curr) {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        };
        return prev;
    };

    
    int pairSum(ListNode *head) {
        int best = INT_MIN;
        ListNode *slow = head, *fast = head, *dummySlow;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next; 
        };
        dummySlow = slow;
        fast = head;
        slow = reverse(slow);
        while (fast != dummySlow) {
            best = max(best, fast->val + slow->val);
            slow = slow->next, fast = fast->next; 
        };
        return best;
    };
};




