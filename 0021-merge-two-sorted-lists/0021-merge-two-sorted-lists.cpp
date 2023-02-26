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
    struct comp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        };    
    };
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<ListNode*, vector<ListNode*>, comp> pq;        
        while (list1) {
            pq.push(list1);
            list1 = list1->next;
        };
        while (list2) {
            pq.push(list2);
            list2 = list2->next;
        };
        if (!pq.empty()) {
            list1 = pq.top(), list2 = list1;
            pq.pop();
        };
        while (!pq.empty()) {
            list1 = list1->next = pq.top();
            pq.pop();
        };
        if (list1) list1->next = nullptr;
        return list2;
    };
};


