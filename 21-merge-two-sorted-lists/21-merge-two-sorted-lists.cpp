// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode * result = new ListNode(69), * temp = result;
        
//         while (l1 && l2) {
//             if (l1->val < l2->val) {
//                 temp = temp->next = l1;
//                 l1 = l1->next;
//             } else {
//                 temp = temp->next = l2;
//                 l2 = l2->next;                
//             };            
//         };
//         if (l1) temp->next = l1;
//         if (l2) temp->next = l2;
//         return result->next;  
//     };
// };

class Solution {
public:
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;            
        };        
    };
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        if (l1) pq.push(l1);
        if (l2) pq.push(l2);
        
        ListNode* dummy = new ListNode(7), * temp = dummy;
        while (!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if (temp->next) pq.push(temp->next);
        };
        return dummy->next;
    };
};







