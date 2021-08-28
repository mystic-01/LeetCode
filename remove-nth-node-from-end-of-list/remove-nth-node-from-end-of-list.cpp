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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        int count = 0;
        ListNode * temp = head, * prev1 = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;  
        };
        n = count - n + 1;
        if (n == 1) return head->next;
        count = 0;
        temp = head;
        while (temp != NULL) {
            count++;
            if (count == n) {
                prev1->next = temp->next;
                break;
            };
            prev1 = temp;
            temp = temp->next;
        };
        return head;
    };
};