class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* nextNode = nullptr, *prev = nullptr, *newHead = head;
        
        for (ListNode* temp = head; temp && temp->next; temp = temp->next) {
            nextNode = temp->next->next; // 3 null
            
            if (temp == head) newHead = temp->next; // 2
            else prev->next = temp->next; // 2->1->4
            
            temp->next->next = temp; // 2->1->4->3
            temp->next = nextNode;  // 2->1->4->3->null
            prev = temp; // 1 3
        };
        return newHead;
    };
};