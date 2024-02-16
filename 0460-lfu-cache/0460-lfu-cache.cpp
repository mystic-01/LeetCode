struct Node {
    int key, val, freq = 0;
    Node *next, *prev;

    Node() {
        
    };
    Node(int _key, int _val, int _freq, Node *_next, Node *_prev) {
        key = _key, val = _val, freq = _freq, next = _next, prev = _prev;    
    };    
};

class List {
public:
    int size = 0;
    Node *head, *tail;

    List() {
        head = new Node(), tail = new Node();
        head->next = tail;
        tail->prev = head;
    };
    
    Node *addAfterHead(int &key, int &val, int &freq) {
        Node *node = new Node(key, val, freq, head->next, head);
        node->next->prev = node;    
        head->next = node;
        ++size;
        return node;
    };
    
    void remove(Node *node) {
        node->next->prev = node->prev;    
        node->prev->next = node->next;
        --size;
    };
};

class LFUCache {
public:
    int cap = 0, lowestFreq = 0;
    unordered_map<int, List*> freqMap;
    unordered_map<int, Node*> nodeMap;
    
    // DO FAST!, with 20 min timer!        
    LFUCache(int capacity) {
        cap = capacity;
    };

    void removeNodeAndUpdateFreqMap(int freq, Node *node) {
        List *currList = freqMap[freq];
        if (!node) {
            node = currList->tail->prev;
        };
        nodeMap.erase(node->key);
        currList->remove(node);
        if (freqMap[freq]->size == 0 && lowestFreq == freq) {
            lowestFreq = freq + 1;    
        };
    };    
    
    void addNodeAndUpdateFreqMap(int &key, int &val, int freq) {
        List *newList = new List();
        if (freqMap.find(freq) != freqMap.end()) {
            newList = freqMap[freq];
        };
        freqMap[freq] = newList;
        Node *newNode = newList->addAfterHead(key, val, freq);
        nodeMap[key] = newNode;           
    };
    
    void bumpUpFreq(Node *node, int &val, int freq) {
        // remove from currList
        removeNodeAndUpdateFreqMap(freq, node);
        // Add after head in nextList
        addNodeAndUpdateFreqMap(node->key, val, freq + 1);
    };
    
    int get(int key) {
        int ans = -1;
        if (nodeMap.find(key) != nodeMap.end()) {
            ans = nodeMap[key]->val;
            bumpUpFreq(nodeMap[key], nodeMap[key]->val, nodeMap[key]->freq);
        };
        return ans;
    };
    
    void put(int key, int value) {
        if (nodeMap.find(key) != nodeMap.end()) {
            bumpUpFreq(nodeMap[key], value, nodeMap[key]->freq);
        } else {
            if (cap-- <= 0) {
                removeNodeAndUpdateFreqMap(lowestFreq, nullptr);                                
            };
            lowestFreq = 0;
            addNodeAndUpdateFreqMap(key, value, lowestFreq);
        };        
    };
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */