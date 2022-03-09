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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        ListNode * dummy = new ListNode(961), * prev = dummy, * temp = head;
        prev->next = temp;
        
        while (temp) {
            if (temp->next && temp->val == temp->next->val) {
                int val = temp->val;
                while (temp && temp->val == val) temp = temp->next;
            } else {
                prev = prev->next = temp;
                temp = temp->next;
            };
        };
        prev = prev->next = temp;
        return dummy->next;
    };
};