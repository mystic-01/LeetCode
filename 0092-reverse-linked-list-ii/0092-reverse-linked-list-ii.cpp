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
    ListNode* reverse(ListNode *start, ListNode *end) {
        ListNode *curr = start, *prev = end->next, *limit = end->next, *nextNode = nullptr;
        while (curr != limit) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        };
        return prev;
    };
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(69),  *prevOfLeft = dummy, *start = nullptr, *temp = head;
        dummy->next = head;
        
        while (right) {
            left--, right--;

            if (left == 0) start = temp;
            else if (left > 0) prevOfLeft = prevOfLeft->next;
            
            if (right == 0) prevOfLeft->next = reverse(start, temp);
            temp = temp->next;
        };
        
        return dummy->next;
    };
};