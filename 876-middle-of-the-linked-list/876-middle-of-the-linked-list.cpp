
// class Solution {
// public:
//     int count = 1, middle = 0;
//     ListNode* middleNode(ListNode* head) {
//         ListNode *temp = head;
//         while(temp->next != NULL) {
//             temp = temp->next;
//             count++;
//         }
//         temp = head, middle = count/2 + 1, count = 1;
//         while(temp->next != NULL) {
//             if (count == middle) return temp;
//             temp = temp->next;
//             count++;
//         };
//         return temp;
//     };
// };

class Solution {
    public:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        return slow;
    };
};





