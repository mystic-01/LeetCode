/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     // HashSet Solution
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> s;
//         ListNode* temp = headA;
//         while (temp) {
//             s.insert(temp);
//             temp = temp->next;
//         };
//         temp = headB;
//         while (temp) {
//             if (s.find(temp) != s.end()) return temp;
//             temp = temp->next;
//         };
//         return temp;
//     };
// };

class Solution {
public:
    // O(2n) Solution
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode* tempA = headA, * tempB = headB;
        int a = 0, b = 0;
        while (tempA || tempB) {
            if (tempA) a++, tempA = tempA->next;
            if (tempB) b++, tempB = tempB->next;
        };
        tempA = headA, tempB = headB;
        int steps = abs(a - b);
        if (a > b) {
            while (steps--) tempA = tempA->next;
        } else {
            while (steps--) tempB = tempB->next;
        };
        while (tempA) {
            if (tempA == tempB) return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        };
        return tempA;
    };
};




