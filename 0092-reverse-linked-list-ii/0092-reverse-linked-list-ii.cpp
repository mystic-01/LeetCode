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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        int count = 0;
        ListNode * temp = head, * prev = head, * nextNode, * rightPointer, * rightNext;
        
        while (temp != NULL) {
            count++;
            if (count == right) {
                rightPointer = temp;
                rightNext = temp->next;
                break;
            }
            temp = temp->next;
        };
        temp = head;
        count = 0;
        
        while (temp != NULL) {
            count++;
            if (count == left) {
                ListNode * leftPointer = temp;
                nextNode = temp->next;
                prev->next = rightPointer;
                prev = temp;
                temp = nextNode;
                count++;
                while (count <= right && temp != NULL) {
                    nextNode = temp->next;
                    temp->next = prev;
                    prev = temp;
                    temp = nextNode;
                    count++;
                }
                leftPointer->next = rightNext;
                if (left == 1) {
                    return rightPointer;
                }
                break;
            }
            nextNode = temp->next;
            prev = temp;
            temp = nextNode;
        };
        return head;
    };
};