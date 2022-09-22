class MagicDictionary {
private:
    vector<string> dict;
    
public:
    MagicDictionary() {
        
    };
    
    void buildDict(vector<string> dictionary) {
        dict = dictionary;
    };
    
    bool search(string searchWord) {
        int n = searchWord.length();
        
        for (auto &str : dict) {
            if (str.length() != n) continue;
            
            int diff = 0;
            for (auto i = 0; i < n; i++) diff += (searchWord[i] != str[i]) ? 1 : 0;
            if (diff == 1) return true;
        };    
        
        return false;
    };
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */