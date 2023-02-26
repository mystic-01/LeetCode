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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;  
        while (fast && fast->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) break;
        };
        
        if (!(fast && fast->next)) return nullptr;
        fast = head;
        
        while (slow != fast) slow = slow->next, fast = fast->next;                
        return slow;
    };
};

/* Explanation :

L1 is the distance outside the cycle
L2 is the distance from *Cycle Start* to *Meeting Point*
C is the length of cycle

d(slow) = L1 + L2
d(fast) = L1 + L2 + n(C) 

speed(fast) = 2 * speed(slow)
L1 + L2 + nC = 2 * (L1 + L2)
L1 + L2 = nC
L1 = nC - L2

    

*/




