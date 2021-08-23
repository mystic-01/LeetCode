/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int temp;
        while (node->next->next != NULL) {
            temp = node->next->val;
            node->next->val = node->val;
            node->val = temp;
            node = node->next;
        };
        node->val = node->next->val;
        node->next = NULL;
        delete node->next;
    };
};