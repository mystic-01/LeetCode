struct Node {
    int val;
    Node* next;
        
    Node(int _val, Node* _next) {
        val = _val, next = _next;
    };
};

class MyCircularQueue {

private:
    int size = 0, limit = 0;
    Node *head = nullptr, *tail = nullptr;
    
public:
    MyCircularQueue(int k) {
        limit = k;
    };
    
    bool enQueue(int value) {
        if (size == limit) return false;
        if (size == 0) tail = head = new Node(value, nullptr), size++;
        else tail = tail->next = new Node(value, nullptr), size++;
        return true;
    };
    
    bool deQueue() {
        if (size == 0) return false;
        if (size == 1) tail = head = head->next, size--;
        else head = head->next, size--;
        return true;
    };
    
    int Front() {
        return head ? head->val : -1;        
    };
    
    int Rear() {
        return tail  ? tail->val : -1;                
    };
    
    bool isEmpty() {
        return !size;        
    };
    
    bool isFull() {
        return size == limit;        
    };
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */