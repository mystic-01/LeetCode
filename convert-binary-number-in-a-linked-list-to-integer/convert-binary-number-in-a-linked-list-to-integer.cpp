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
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        if (head == NULL) {
            // return pow(head->val, 0);
            return 1;
        }
        int count = 0, sum = 0;
        while (temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        temp = head;
        while (temp != NULL) {
            if (temp->val) sum += pow(2, count);
            temp = temp->next;
            count--;
        }
        return sum;
    };
};