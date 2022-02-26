class Solution {
public:
    ListNode* reverse(ListNode* curr) {
        ListNode* prev = nullptr, * newNode = nullptr;
        while (curr) {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        };
        return prev;
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headA = reverse(l1), * headB = reverse(l2);
        
        ListNode* tempA = headA, * tempB = headB, * dummy = new ListNode(7), * d = dummy;
        int carry = 0;
        while (tempA || tempB || carry) {
            if (tempA) carry += tempA->val, tempA = tempA->next;
            if (tempB) carry += tempB->val, tempB = tempB->next;
            d = d->next = new ListNode(carry % 10);
            carry /= 10;
        };
        return reverse(dummy->next);
    };
};




