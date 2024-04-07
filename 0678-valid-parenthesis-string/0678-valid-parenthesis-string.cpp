class Solution {
public:
    bool checkValidString(string s) {
        int open = 0, close = 0, aestrik = 0;
        for (char &ch : s) {
            if (ch == '(') {
                ++open;
            } else if (ch == '*') {
                ++aestrik;                
            } else {
                if (open) {
                    --open;
                } else if (aestrik) {
                    --aestrik;
                } else {
                    return false;
                };
            };            
        };
        
        reverse(begin(s), end(s));
        open = 0, close = 0, aestrik = 0;
        for (char &ch : s) {
            if (ch == ')') {
                ++close;
            } else if (ch == '*') {
                ++aestrik;                
            } else {
                if (close) {
                    --close;
                } else if (aestrik) {
                    --aestrik;
                } else {
                    return false;
                };
            };            
        };        
        return true;
    };
};