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
    ListNode *reverse(ListNode *curr) {
        ListNode *prev = nullptr, *nextNode = nullptr;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        };
        return prev;
    };
    
    void reorderList(ListNode *head) {
        // reverse from midpoint
        if (!head || !head->next) {
            return;    
        };
        // ListNode *dummy = new ListNode(69, head), *slow = dummy, *fast = dummy;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        fast = reverse(slow->next);
        slow->next = nullptr;
        slow = head;
        while (slow && fast && (slow != fast)) {
            ListNode *temp = slow->next;
            slow->next = fast;
            fast = fast->next;
            slow->next->next = temp;
            slow = slow->next->next;
        };
    };
};

/*

temp = head->next;
head->next = secondLast->next;
head->next->next = temp;
secondLast->next = nullptr;

*/