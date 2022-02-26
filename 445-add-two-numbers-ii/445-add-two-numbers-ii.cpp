class Solution {
public:
    pair<ListNode*, int> reverse(ListNode* curr) {
        int size = 0;
        ListNode* prev = nullptr, * newNode = nullptr;
        while (curr) {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
            size++;
        };
        return {prev, size};
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        pair<ListNode*, int> pairA = reverse(l1), pairB = reverse(l2);
        ListNode * headA = pairA.first, * headB = pairB.first;
        bool takeFirst = pairA.second > pairB.second;
        
        ListNode* tempA = headA, * tempB = headB;
        int carry = 0;
        if (takeFirst) {
            while (tempA) {
                carry += tempA->val;
                if (tempB) carry += tempB->val, tempB = tempB->next;
                tempA->val = carry % 10;
                carry /= 10;
                if (!tempA->next) break;
                tempA = tempA->next;
            };
            if (carry) tempA->next = new ListNode(carry % 10);
            return reverse(headA).first;
            
        } else {
            while (tempB) {
                carry += tempB->val;
                if (tempA) carry += tempA->val, tempA = tempA->next;
                tempB->val = carry % 10;
                carry /= 10;
                if (!tempB->next) break;
                tempB = tempB->next;
            };
            if (carry) tempB->next = new ListNode(carry % 10);   
            return reverse(headB).first;
        };
    };
};




