class Solution {
public:
    string toLowerCase(string s) {
        for (auto &c : s) {
            int diff = c - 'A';
            if (diff >= 0 && diff < 26) c = char(97 + diff);    
        };
        
        return s;
    };
};