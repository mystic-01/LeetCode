struct Node {
    Node* links[26] = {nullptr};
    bool countIndices[100] = {0};
    int count = 0;
    
    bool contains(char &ch) {
        return links[ch - 'a'];
    };
    
    void put(char &ch) {
        links[ch - 'a'] = new Node();
    };
};

class Trie {
private:
    Node* root = new Node();
public:
    Trie() {
        
    };
    
    void insert(string &word, int &idx) {
        Node* temp = root;
        for (auto i = 0; i < word.length(); i++) {
            if (!temp->contains(word[i])) temp->put(word[i]);
            temp = temp->links[word[i] - 'a'];
        };
        temp->count += !temp->countIndices[idx];
        temp->countIndices[idx] = true;
    };
    
    bool finder(string &word) {
       Node* temp = root;
        for (auto i = 0; i < word.length(); i++) {
            if (!temp->contains(word[i])) return false;
            temp = temp->links[word[i] - 'a'];
        };
        return temp->count == 1;
    };
    
    bool startsWithOneCount(string &prefix) {
        return finder(prefix);
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
                    trie->insert(curr, idx);  
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
                    int shortestSize = shortest.size(); 
                    if ((!shortestSize || len < shortestSize || (len == shortestSize && curr < shortest))) {
                        if (trie->startsWithOneCount(curr)) {
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