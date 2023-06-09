class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int count = 0, sSize = s.size(), size = searchWord.size();
        
        for (auto i = 0; i < sSize; i++) {
            count++;
            if (s.substr(i, size) == searchWord) return count;
            while (i < sSize && s[i] != ' ') i++;
        };
        
        return -1;
    };
};