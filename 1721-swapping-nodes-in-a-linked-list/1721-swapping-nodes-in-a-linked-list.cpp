
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0, l;
        struct ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            count++;
        };

        l = count - k + 1;
        temp = head;
        if (k > l) {
            k = k+l;
            l = k-l;
            k = k-l;
        }
        if (count == 1 || k == l) return head;
        if (count == 2) {
            struct ListNode * temp1, * temp2, * middle;
            temp1 = head;
            temp2 = head->next;
            temp2->next = temp1;
            temp1->next = NULL;
            return temp2;
        }
        
        struct ListNode * prev1, * temp1, * next1, * prev2, * temp2, * next2;
        struct ListNode * PREV = temp, * NEXT = temp;

        int flag1 = 0, flag2 = 0;
        count = 0;
        
        // Head/Tail Node
        if (k == 1) {
            prev1 = PREV;
            temp1 = temp;
            next1 = temp->next;
            while (temp != NULL) {
                count++;
                if (count == l && flag2 == 0) {
                    flag2 = 1;
                    prev2 = PREV;
                    temp2 = temp;
                    next2 = temp->next;
                    break;
                }
                PREV = temp;
                temp = temp->next;
                NEXT = temp->next;
            };
        } else if (l == 1) {
            prev1 = PREV;
            temp1 = temp;
            next1 = temp->next;
            while (temp != NULL) {
                count++;
                if (count == k && flag2 == 0) {
                    flag2 = 1;
                    prev2 = PREV;
                    temp2 = temp;
                    next2 = temp->next;
                    break;
                }
                PREV = temp;
                temp = temp->next;
                NEXT = temp->next;
            };
        }
        
        if (k == 1 || l == 1) {
            prev2->next = temp1;
            prev2->next->next = NULL;
            temp1 = temp2;
            temp1->next = next1;
            return temp1;
        }
        
        // General Case         
        while (temp != NULL) {
            count++;
            if (count == k && flag1 == 0) {
                flag1 = 1;
                prev1 = PREV;
                temp1 = temp;
                next1 = temp->next;
            } else if (count == l && flag2 == 0) {
                flag2 = 1;
                prev2 = PREV;
                temp2 = temp;
                next2 = temp->next;
            }
            if (flag1 && flag2) break;
            PREV = temp;
            temp = temp->next;
            NEXT = temp->next;
        };
        
        // Adjacent Case         
        if (k - l == 1 || l - k == 1) {
            prev1->next = temp2;
            prev1->next->next = temp1;
            prev1->next->next->next = next2;
            return head;
        } 
        
        prev1->next = temp2;
        prev1->next->next = next1;
        
        prev2->next = temp1;
        prev2->next->next = next2;
        return head;
    };
};