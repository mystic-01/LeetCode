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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(temp == nullptr) return temp;

        int n = 1, count = 1;
        while(temp->next) {
            n++;
            temp = temp->next;
        };
        k %= n;
        temp->next = head;
        
        temp = head;
        while(count < n - k) {
            count++;
            temp = temp->next;
        };        
        
        ListNode* ans = temp->next;
        temp->next = nullptr;
        return ans;
    };
};