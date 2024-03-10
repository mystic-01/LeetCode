struct Node {
    Node* links[26] = { nullptr };
    bool flag = false;
    unordered_set<int> countIndices;
    
    bool contains(char c) {
        return links[c - 'a'];
    };
    
    void put(char c) {
        links[c - 'a'] = new Node();
    };
};

class Trie {
public:
    Node* root = new Node();

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
    
    bool finder(string word, int idx, string fun) {
       Node* temp = root;
        for (auto i = 0; i < word.length(); i++) {
            if (!temp->contains(word[i])) return false;
            temp = temp->links[word[i] - 'a'];
        };
        return fun == "search" ? temp->flag : (temp->countIndices.size() <= 1);
    };
    
    bool search(string word) {
        return finder(word, -1, "search");
    };
    
    
    bool startsWithOneCount(string prefix, int idx) {
        return finder(prefix, idx, "startsWith");
    };    
};


class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size(), idx = 0;
            
        Trie* trie = new Trie();    
        for (string &str : arr) {
            int stringSize = str.size();
            for (int i = 0; i < stringSize; ++i) {
                for (int len = 1; len + i <= stringSize; ++len) {
                    string curr = str.substr(i, len);
                    Node* node = trie->root;  
                    for (char &ch : curr) {
                        if (!node->contains(ch)) {
                            node->put(ch);
                        };
                        node = node->links[ch - 'a'];
                    };        
                    node->countIndices.insert(idx);
                };                                    
            };  
            ++idx;
        };      
        idx = 0;
        for (string &stri : arr) {
            string shortest = "";
            int stringSize = stri.size();
            for (int i = 0; i < stringSize; ++i) {
                for (int len = 1; len + i <= stringSize; ++len) {
                    string curr = stri.substr(i, len);
                    int cSize = curr.size(), sSize = shortest.size(); 
                    if ((!sSize || cSize < sSize || (cSize == sSize && curr < shortest))) {
                        if (trie->startsWithOneCount(curr, idx)) {
                            shortest = curr;        
                        };
                    };                        
                };                                    
            };       
            arr[idx++] = shortest;
        };  
        return arr;
    };
};