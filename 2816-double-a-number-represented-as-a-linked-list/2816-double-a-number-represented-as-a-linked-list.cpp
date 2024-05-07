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
    ListNode* doubleIt(ListNode* head) {
        vector<int> num;
        ListNode* temp = head;
        
        while (temp) {
            num.push_back(temp->val);
            temp = temp->next;
        };
        
        int carry = 0;
        for (int i = num.size() - 1; i >= 0; i--) {
            num[i] *= 2;
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
        };
        
        if (carry) num.insert(num.begin(), carry);
        
        ListNode *curr = new ListNode(0);
        head = curr;
        for (int i = 0; i < num.size(); i++) {
            ListNode *newNode = new ListNode(num[i]);
            curr = curr->next = newNode;
            
        };
        
        return head->next;
    };
};