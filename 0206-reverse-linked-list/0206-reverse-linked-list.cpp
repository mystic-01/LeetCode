class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *prev = nullptr, *nextNode = nullptr;        
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        };
        return prev;
    };
};

































