struct Node {
    Node* links[26] = { nullptr };
    bool flag = false;
    
    bool contains(char c) {
        return links[c - 'a'];
    };
    
    void put(char c) {
        links[c - 'a'] = new Node();
    };
    
};

class Trie {
private:
    Node* root = new Node();
    
public:
    Trie() {
        
    };
    
    void insert(string word) {
        Node* temp = root;
        for (auto i = 0; i < word.length(); i++) {
            if (!temp->contains(word[i])) temp->put(word[i]);
            temp = temp->links[word[i] - 'a'];
        };
        temp->flag = true;
    };
    
    bool finder(string word, string fun) {
       Node* temp = root;
        for (auto i = 0; i < word.length(); i++) {
            if (!temp->contains(word[i])) return false;
            temp = temp->links[word[i] - 'a'];
        };
        return fun == "search" ? temp->flag : true;
    };
    
    bool search(string word) {
        return finder(word, "search");
    };
    
    bool startsWith(string prefix) {
        return finder(prefix, "startsWith");
    };
};


















/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */