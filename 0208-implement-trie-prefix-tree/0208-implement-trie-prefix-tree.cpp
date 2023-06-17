struct TrieNode {
    TrieNode *child[26] = {nullptr};
    bool isWord = false;
};

class Trie {

private:
    TrieNode* root = new TrieNode();

public:
    Trie() {

    };
    
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        };
        p->isWord = true;
    };
    
    bool search(string key, bool prefix = false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        };
        return (!prefix) ? p->isWord : true;
    };
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    };
};