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
    bool hasCycle(ListNode *head) {
       
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
        ListNode* slow = head, * fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;            
            fast = fast->next->next;  
            if (slow == fast) return true;
        };
        return false;
    };
};