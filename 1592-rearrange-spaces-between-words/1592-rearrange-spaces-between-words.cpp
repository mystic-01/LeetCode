class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size(), totalSpaces = 0, words = 0, i = 0;
        while (i < n) {
            if (text[i] == ' ') {    
                while (i < n && text[i] == ' ') {
                    ++totalSpaces, ++i;    
                };  
            } else {
                ++words;
                while (i < n && text[i] != ' ') {
                    ++i;    
                };              
            };
        };
        string ans = "";
        int left = 0, spacesPerSlot = totalSpaces / max(1, words - 1);
        for (int i = 0; i < n; ++i) {
            if (text[i] != ' ') {    
                while (i < n && text[i] != ' ') {
                    ans += text[i++];    
                };              
                for (int k = 0, limit = min(totalSpaces, spacesPerSlot); k < limit; ++k) {
                    ans += ' ', --totalSpaces;                        
                };
            };
        };
        for (int k = 0; k < totalSpaces; ++k) {
            ans += ' ';                        
        };        
        return ans;
    };
};