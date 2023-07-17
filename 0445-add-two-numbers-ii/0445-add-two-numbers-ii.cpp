class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *temp = head, *nextNode = nullptr;
        while (temp) {
            nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        };
        return prev;
    };
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;
        
        l1 = reverse(l1);            
        l2 = reverse(l2);
        
        int carry = 0;
        ListNode *head = l1;
        
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            l1->val = digit;
            if (l2) l2 = l2->next;

            if ((l2 || carry) && (!l1->next)) l1->next = new ListNode(0);
            
            if (l1) l1 = l1->next;
        };
        
        head = reverse(head);            
        return head;
    };
};