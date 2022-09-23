// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int count = -1;
//         ListNode * dummy = new ListNode(69), * temp = dummy;
//         dummy->next = head;
//         while (temp) {
//             temp = temp->next;
//             count++;  
//         };
//         temp = dummy;
//         while (temp) {
//             if (count == n) temp->next = temp->next->next;
//             temp = temp->next;
//             count--;
//         };
//         return dummy->next;
//     };
// };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode(0), * slow = dummy, * fast = dummy;
        dummy->next = head;
        int count = n;
        while (count--) fast = fast->next;            

        while (fast->next) slow = slow->next, fast = fast->next;

        slow->next = slow->next->next;
        return dummy->next;
    };
};











