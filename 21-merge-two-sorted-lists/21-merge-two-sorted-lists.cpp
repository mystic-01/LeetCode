class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
//         if (!l1) return l2;
//         else if (!l2) return l1;

        ListNode * result = new ListNode(69), * temp = result;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp = temp->next = l1;
                l1 = l1->next;
            } else {
                temp = temp->next = l2;
                l2 = l2->next;                
            };            
        };
        if (l1) temp->next = l1;
        if (l2) temp->next = l2;
        return result->next;  
    };
};