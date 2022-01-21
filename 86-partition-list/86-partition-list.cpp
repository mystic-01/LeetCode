class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* newHead = new ListNode(69), * prev = new ListNode(69);
        prev->next = head;
        ListNode * curr = head, * newCurr = newHead, * newPrev = prev;
        
        while (curr) {
            if (curr->val < x) {
                newCurr = newCurr->next = curr;
                newPrev->next = curr->next;
            } else {
                newPrev = curr;
            };
            curr = curr->next;
        };
        newCurr->next = prev->next;
        return newHead->next;
    };
};