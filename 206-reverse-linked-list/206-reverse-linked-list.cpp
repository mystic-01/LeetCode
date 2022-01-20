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
    ListNode* reverseList(ListNode* head) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        ListNode* prev = nullptr, * current = head, * next;
        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        };
        return prev;
    };
};