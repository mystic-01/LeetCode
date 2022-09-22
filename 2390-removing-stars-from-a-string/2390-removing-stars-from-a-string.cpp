class Solution {
public:
    string removeStars(string s) {
        int n = s.length(), start = 0, i = 0;        
    
        while (i < n) {
            if (s[i] == '*') start--;
            else s[start] = s[i], start++;
            i++;
        };
    
        return s.substr(0, start);
    };
};