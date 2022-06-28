class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), i = n - 1, count = 0;
        while (s[i] == ' ') i--;
        while (i >= 0 && s[i] != ' ') count++, i--;
        return count;
    };
};