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
        
        ListNode * temp = head;
        unordered_set<int> s;
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
                s.insert(temp->val);
            } else temp = temp->next;
        };
        temp = head;
        while (temp && temp->next) {
            if (s.count(temp->next->val)) temp->next = temp->next->next;
            else temp = temp->next;
        };
        if (s.count(head->val)) return head->next;
        return head;
    };
};