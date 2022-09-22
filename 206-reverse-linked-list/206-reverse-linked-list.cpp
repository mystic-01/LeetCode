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
    ListNode* reverse(ListNode* head, ListNode* prev) {
        if(!head->next) {
            prev->next = head;
            return head;
        };
        
        ListNode* temp = reverse(head->next, prev);
        temp->next = head;
        return head;
    };

    
    ListNode* reverseList(ListNode* head) {
        
//         ListNode* prev = new ListNode(69), * current = head, * next;
// //         while (current) {
// //             next = current->next;
// //             current->next = prev;
          
// //             prev = current;
// //             current = next;
// //         };
//         ListNode* ans = reverse(head, prev);
//         return prev;
        ListNode *prev = nullptr, *curr = head, *newNode;
        while (curr) {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        };
        return prev;
        
    };
};