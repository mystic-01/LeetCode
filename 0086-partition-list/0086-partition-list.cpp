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
    ListNode* partition(ListNode* head, int x) {
        ListNode *dummy = new ListNode(69), *prev, *lastSmall, *curr = head;
        dummy->next = head, lastSmall = dummy, prev = dummy;
        
        while (curr) {
            if (curr->val < x) {
                if (lastSmall->next == curr) {
                    lastSmall = prev = curr, curr = curr->next;
                } else {
                    // Detach curr and join prev with curr's next
                    prev->next = curr->next;                

                    // Attach curr's next to last small's next; Then attach last small's next to curr and move lastSmall forward 
                    curr->next = lastSmall->next;
                    lastSmall = lastSmall->next = curr;

                    // Move Curr forward
                    curr = curr->next;
                };
            } else prev = curr, curr = curr->next;                        
        };
        
        return dummy->next;
    };
};