struct Node {
    int val;
    Node *prev, *next;
    Node(int _val, Node *_prev, Node *_next) {
        val = _val, prev = _prev, next = _next;        
    };
};

class MyCircularDeque {
private:
    int currSize = 0, maxSize = 0;
    Node *head = new Node(69, nullptr, nullptr), *tail = new Node(69, nullptr, nullptr);
public:
    MyCircularDeque(int k) {
        maxSize = k;    
        head->next = tail;
        tail->prev = head;
    };
    
    bool insertFront(int value) {
        if (currSize == maxSize) return false;
        Node *TBA = new Node(value, head, head->next);
        TBA->next->prev = TBA;
        head->next = TBA;
        ++currSize;
        return true;
    };
    
    bool insertLast(int value) {
        if (currSize == maxSize) return false;
        Node *TBA = new Node(value, tail->prev, tail);
        TBA->prev->next = TBA;
        tail->prev = TBA;
        ++currSize;
        return true;
    };
    
    bool deleteFront() {
        if (currSize == 0) return false;
        Node *TBD = head->next;
        head->next = TBD->next;
        TBD->next->prev = head;
        --currSize;
        return true;
    };
    
    bool deleteLast() {
        if (currSize == 0) return false;
        Node *TBD = tail->prev;
        tail->prev = TBD->prev;
        TBD->prev->next = tail;
        --currSize;
        return true;
    };
    
    int getFront() {
        return head->next == tail ? -1 : head->next->val;                
    };
    
    int getRear() {
        return tail->prev == head ? -1 : tail->prev->val;        
    };
    
    bool isEmpty() {
        return !currSize;        
    };
    
    bool isFull() {
        return currSize == maxSize;    
    };
};