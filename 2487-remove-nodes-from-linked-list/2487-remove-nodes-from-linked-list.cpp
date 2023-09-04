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
    ListNode* reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *nextNode = nullptr;
        while (curr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        };
        return prev;
    };
    
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        
        ListNode *prev = head, *temp = head->next;
        while (temp) {
            if (temp->val < prev->val) prev->next = temp->next;
            else prev = prev->next;
            temp = temp->next;            
        };
        
        return reverse(head);
    };
};