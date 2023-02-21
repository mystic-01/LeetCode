class Solution {
public:
    ListNode* reverse(ListNode* head, ListNode* prev) {
        if(!head->next) {
            prev->next = head;
            return head;
        };
        
        ListNode* temp = reverse(head->next, prev);
        temp->next = head;
        return head;
    };

    
    ListNode* reverseList(ListNode* head) {
        
        if (!head) return head;
        ListNode* prev = new ListNode(69);
        ListNode* ans = reverse(head, prev);
        ans->next = nullptr;
        return prev->next;
        
        // ListNode *prev = nullptr, *curr = head, *newNode;
        // while (curr) {
        //     newNode = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = newNode;
        // };
        // return prev;
        
    };
};