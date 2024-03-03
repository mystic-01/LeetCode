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
    void reverse(ListNode *prev, ListNode *head, ListNode *postEnd, int k) {
        ListNode *temp = head, *nextNode = nullptr;
        while (temp && k--) {
            nextNode = temp->next;
            temp->next = postEnd;
            postEnd = temp;
            temp = nextNode;
        };
        if (prev) {
            prev->next = postEnd;    
        };
    };
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *curr = head, *start = head, *prev = nullptr;
        while (curr) {
            if (count && count % k == 0) {
                reverse(prev, start, curr, k);
                prev = start, start = curr;
            };
            if (count == k - 1) {
                head = curr;    
            };
            ++count, curr = curr->next;
        };         
        if (count % k == 0) {
            reverse(prev, start, curr, k);            
        };
        
        return head;
    };
};