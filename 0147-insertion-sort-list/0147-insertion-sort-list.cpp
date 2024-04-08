class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN, head), *temp = head;
        
        while (temp) {
            if (temp->next && temp->next->val < temp->val) {
                ListNode *toBeRemoved = temp->next;
                ListNode *start = dummy;
                while (start != temp && start->next->val < toBeRemoved->val) {
                    start = start->next;
                };   
                temp->next = toBeRemoved->next;
                toBeRemoved->next = start->next;
                start->next = toBeRemoved;
            } else {
                temp = temp->next;            
            };
        };
        
        return dummy->next;
    };
};