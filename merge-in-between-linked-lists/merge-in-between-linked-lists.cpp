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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp = list1;
        ListNode *temp2 = list2;
        
        int i = 1, j = 0;
        while (j <= b) {
            temp = temp->next;   
            j++;
        }
        while (temp2->next != nullptr) {
            temp2 = temp2->next;   
        }
        temp2->next = temp;
        temp = list1;
        while (i < a) {
            temp = temp->next;   
        i++;
        }
        temp->next = list2;
        return list1;
    };
};
