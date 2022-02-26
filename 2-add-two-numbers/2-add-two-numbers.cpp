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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0, carry = 0;
        ListNode* dummy = new ListNode(7), * temp = dummy;
        while (l1 || l2 || carry) {
            sum = carry;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            carry = sum / 10; 
            if (l1 && l1->next) {
                l1->val = sum % 10;
                temp = temp->next = l1;
            } else {
                ListNode* newNode = new ListNode(sum % 10);
                temp = temp->next = newNode;
            };
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        };
        return dummy->next;
    };
};