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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        vector<ListNode*> ans(k);
        ListNode *temp = head;
        while (temp) size++, temp = temp->next;
        
        temp = head;
        for (int i = 0; size; i++, k--) {
            int itemSize = ceil(size / (double)k);
            size -= itemSize;

            ListNode* itemHead = temp, *prev = nullptr;
            ans[i] = itemHead;
            
            while (itemSize--) prev = itemHead, itemHead = itemHead->next, temp = temp->next; 
            if (prev) prev->next = nullptr;
        };
        
        return ans;
    };
};