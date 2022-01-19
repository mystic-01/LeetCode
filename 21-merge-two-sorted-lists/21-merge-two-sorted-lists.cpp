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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
       

        if (!l1 && !l2) return NULL; 
        else if (!l1) return l2;
        else if (!l2) return l1;

        ListNode * result = (l1->val > l2->val) ? l2 : l1;
        if (l1->val > l2->val) {
            l2 = l2->next;
        } else {
            l1 = l1->next;
        }
        ListNode * head = result;

      while (l1 != NULL && l2 != NULL) {
          if (l1->val > l2->val) {
              result->next = l2;
              l2 = l2->next;
          } else {
              result->next = l1;
              l1 = l1->next;
          }
          result = result->next;
      };  
      if (l1) result->next = l1;
      if (l2) result->next = l2;
      return head;  
    };
};