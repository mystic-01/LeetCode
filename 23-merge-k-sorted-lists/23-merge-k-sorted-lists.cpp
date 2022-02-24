class Solution {
public:
    struct comp {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;            
        };
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(69);
        ListNode* temp = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;
        
        for (auto i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        };
        
        while(!pq.empty()) {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;
            if (temp->next) pq.push(temp->next);
        };
        return dummy->next;
    };
};