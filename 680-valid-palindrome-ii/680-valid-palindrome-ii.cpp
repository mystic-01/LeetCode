class Solution {
public:
    bool isPalindrome (string s) {
        int n = s.length(), i = 0, j = n - 1;
        while (i < j)
            if (s[i++] != s[j--]) return false;
        return true;
    };
    
    bool validPalindrome(string &s) {
        int n = s.length(), i = 0, j = n - 1, diff = 0;
        while (i < j)
            if (s[i] != s[j])
                return isPalindrome(s.substr(i, j - i)) || isPalindrome(s.substr(i + 1, j - i)); 
            else i++, j--;             
        return true;
    };
};