struct Node {
    int val, key;
    Node *prev, *next;
    
    Node(int _val) {
        val = _val, prev = nullptr, next = nullptr;
    };
    
    Node(int _val, int _key, Node *_prev, Node *_next) {
        val = _val, key = _key, prev = _prev, next = _next;
    };
};

class LRUCache {
private:
    int insertsLeft;
    Node *head = new Node(0), *tail = new Node(0);
    unordered_map<int, Node*> m;

    void addNode(Node *curr) {
        curr->next = head->next;
        curr->prev = head;        
        head->next->prev = curr;
        head->next = curr;
    };
    
    Node *removeNode(Node *curr) {
        Node *nextNode = curr->next;
        curr->prev->next = nextNode;
        nextNode->prev = curr->prev;
        return curr;
    };
    
public:
    LRUCache(int capacity) {
        insertsLeft = capacity;
        head->next = tail;
        tail->prev = head;
    };
    
    int get(int key) {
        int ans = -1;
        if (m.find(key) != m.end()) {
            ans = m[key]->val;
            Node *curr = removeNode(m[key]);
            addNode(curr);
        };
        return ans;
    };
    
    void put(int key, int value) {
        Node *curr = new Node(value, key, head, head->next);
        if (m.find(key) != m.end()) {
            curr = removeNode(m[key]);
            curr->val = value;
            m.erase(key);
        } else if (insertsLeft == 0) {
            m.erase(tail->prev->key);        
            removeNode(tail->prev);
        } else insertsLeft--;

        addNode(curr);
        m[key] = curr;
    };
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */