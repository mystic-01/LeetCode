// class Solution {
// public:
    // ListNode* partition(ListNode* head, int x) {
        // ListNode* curr = head;
        // while (curr && curr->next) {
          // if (curr->next->val < x) {
              // ListNode* temp = curr->next;
              // curr->next = curr->next->next;
              // temp->next = head;
              // head = temp;
          // } else {
              // curr = curr->next;
          // };
        // };
        // return head;
    // };
// };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // ListNode *curr = head, * newHead, * newTail, * nHead, * nTail;
        // while (curr) {
        //     if (curr->val < x) {
        //         if (nHead) nHead->next = curr;
        //         else newHead = curr;
        //         nHead = curr;
        //     } else {
        //         if (nTail) nTail->next = curr;
        //         else newTail = curr;
        //         nTail = curr;
        //     }
        //     curr = curr->next;
        // };
        // return newHead;
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        
        ListNode* start = new ListNode(69), * end = new ListNode(69);
        ListNode *curr = head, *temp1 = start, *temp2 = end;
         while(curr){
            if (curr->val < x) {
                temp1->next = curr;
                temp1 = curr;
            } else {
                temp2->next = curr;
                temp2 = curr;
            }
            curr = curr -> next;          
        }
        temp1->next = end->next;
        temp2->next = nullptr;       
        return start->next;
    };
};
