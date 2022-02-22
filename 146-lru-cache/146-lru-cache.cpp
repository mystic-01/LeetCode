class LRUCache {
public:
     struct Node {
        int key, val;
        Node *prev, *next;
        Node (int _key, int _val) {
            key = _key;            
            val = _val;            
        };
    };
    
    int cap;
    unordered_map<int, Node*> m;
    Node *head = new Node(-1, -1), *tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    };
    
    void addNode(int key, int val) {
        Node* newNode = new Node(key, val);
        Node* temp = head->next;
        
        head->next = newNode;
        temp->prev = newNode;
        newNode->prev = head;
        newNode->next = temp;
    };
    
    void deleteNode(Node* del) {
        Node* delPrev = del->prev;
        Node* delNext = del->next;
        
        delPrev->next = delNext;
        delNext->prev = delPrev;
        del->prev = del->next = nullptr;
    };
    
    int get(int key) {
        if (m.find(key) != m.end()) {
            int res = m[key]->val;
            deleteNode(m[key]);
            addNode(key, res);
            m[key] = head->next;
            return res;
        };
        return -1;
    };
    
    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            deleteNode(m[key]);
            m.erase(key);
            
        } else if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        };
        
        addNode(key, value);
        m[key] = head->next;
    };
};


















