class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0, idx = 1;
        ListNode* temp = head;
        while (temp) temp = temp->next, n++;
        n = n - k + 1;
        // Same Node
        if (n == k) return head;
        if (n < k) swap(n, k);
        temp = head;
        
        ListNode* kPrev, * kNext, * kNode, * nPrev, * nNext, * nNode;
        while (temp) {
            if (idx == k - 1) kPrev = temp; 
            if (idx == k + 1) kNext = temp; 
            if (idx == k) kNode = temp; 
            if (idx == n - 1) nPrev = temp; 
            if (idx == n + 1) nNext = temp;        
            if (idx == n) nNode = temp; 
            temp = temp->next, idx++;
        };
        
        // Adjacent Node
        if (n - k == 1) {
            if (k == 1) {
                nNode->next = kNode;
                kNode->next = nullptr;
                return nNode; 
            };
            kPrev->next = nNode;
            nNode->next = kNode;
            kNode->next = nNext;
        }
        
        // Head/Tail Node
        else if (k == 1) {
            nPrev->next = kNode;
            kNode->next = nullptr;
            nNode->next = kNext;
            return nNode;
        }
        
        // General Case
        else {
            cout << "beep";
            kPrev->next = nNode;
            nNode->next = kNext;
            nPrev->next = kNode;
            kNode->next = nNext;
        };
        return head;
    };
};