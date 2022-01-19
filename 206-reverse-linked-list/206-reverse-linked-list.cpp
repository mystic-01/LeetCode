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
        if (head == NULL) return head;
        ListNode *prev = NULL, *current = head, *nextNode = current->next;
        while (current->next != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        };
        current->next = prev;
        return current;
    };
};