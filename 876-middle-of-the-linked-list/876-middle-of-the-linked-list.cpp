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
    int count = 1, middle = 0;
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
            count++;
        }
        temp = head, middle = count/2 + 1, count = 1;
        while(temp->next != NULL) {
            if (count == middle) return temp;
            temp = temp->next;
            count++;
        };
        return temp;
    };
};