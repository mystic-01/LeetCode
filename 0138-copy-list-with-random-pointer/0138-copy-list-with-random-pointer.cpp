/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        Node* temp = head, * oldNode, * ans;
        while (temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        };

        temp = head;
        while (temp) {
            temp->next->random = temp->random ? temp->random->next : nullptr;
            temp = temp->next->next;
        };
        
        temp = head;
        ans = head->next;
        while (temp) {
            oldNode = temp->next->next;
            temp->next->next = temp->next->next ? temp->next->next->next : nullptr;
            temp = temp->next = oldNode;
        };
        return ans;    
    };
};