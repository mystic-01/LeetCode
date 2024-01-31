class Solution {
public:
    bool checkValidString(string s, bool checkedOnce = false) {
        int left = 0, aestrik = 0, right = 0;
        for (char &ch : s) {
            if (ch == '(') ++left;
            else if (ch == '*') ++aestrik;
            else {
                ++right;
                if (right > left + aestrik) return false;
            };    
        };
        
        if (left > right + aestrik) return false;
        int diff = abs(left - right);
        
        if (diff != 0 && aestrik < abs(left - right)) return false;
        reverse(begin(s), end(s));
        for (char &ch : s) {
            ch = ch == ')' ? '(' : (ch == '(' ? ')' : '*');   
        };
        return checkedOnce || checkValidString(s, true);
    };
};