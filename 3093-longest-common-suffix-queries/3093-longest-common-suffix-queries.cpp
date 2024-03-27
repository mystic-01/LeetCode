struct Node {
    int minLen = INT_MAX, minIdx = -1;
    Node *links[26] = {nullptr};
    
    Node(int _minLen, int _minidx) {
        minLen = _minLen, minIdx = _minidx;
    };
    bool containsKey(char &ch) {
        return links[ch - 'a'] != nullptr;
    };
    void insertNode(char &ch, int &len, int &idx) {
        links[ch - 'a'] = new Node(len, idx);                                
    };
};

class Trie {
private:
    Node *root = new Node(INT_MAX, 0);
public:
    Trie() {
        
    };
    void insertString(string &str, int &idx) {
        Node *node = root;
        int n = str.size();
        for (char &ch : str) {
            if (!node->containsKey(ch)) {
                node->insertNode(ch, n, idx);    
            };
            if (n < node->minLen) {
                node->minLen = n, node->minIdx = idx;
            };
            node = node->links[ch - 'a'];
        };    
        if (n < node->minLen) {
            node->minLen = n, node->minIdx = idx;
        };        
    };
    
    int search(string &str) {
        Node *node = root;
        for (char &ch : str) {
            if (!node->containsKey(ch)) {
                return node->minIdx;
            };
            node = node->links[ch - 'a'];
        };            
        return node->minIdx;
    };            
                
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& words, vector<string>& queries) {
        int qSize = queries.size(), idx = 0;
        vector<int> ans(qSize);
        Trie *trie = new Trie();
        for (string &str : words) {
            reverse(begin(str), end(str));
            trie->insertString(str, idx);
            ++idx;
        };
        idx = 0;
        for (string &q : queries) {
            reverse(begin(q), end(q));
            ans[idx++] = trie->search(q);
        };
        return ans;
    };
};
















