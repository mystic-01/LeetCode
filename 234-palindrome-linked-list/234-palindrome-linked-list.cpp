// class Solution {
// public:
//     // O(n) Space solution.
//     bool isPalindrome(ListNode* head) {
//         vector<int> v;
//         ListNode* temp = head;
//         while (temp) {
//             v.push_back(temp->val);
//             temp = temp->next;
//         };
//         int i = 0, j = v.size() - 1;
//         while (i < j && v[i] == v[j]) i++, j--;
//         return v[i] == v[j];
//     };
// };

class Solution {
public:
    ListNode *reverse(ListNode *curr) {
        ListNode *prev = nullptr, *newNode = nullptr;
        while (curr) {
            newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        };
        return prev;
    };
    
    // O(1) Space solution.
    bool isPalindrome(ListNode *head) {
        ListNode *slow = head, *fast = head, *dummySlow;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        };
        if (!fast) {
            // Even list
            dummySlow = slow;
        } else {
            // Odd list
            dummySlow = slow;
            slow = slow->next;
        };
        fast = head;
        slow = reverse(slow);
        while (fast != dummySlow) {
            if (fast->val != slow->val) return false;
            fast = fast->next, slow = slow->next;
        };
        return true;
    };
};

