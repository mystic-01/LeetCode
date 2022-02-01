class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto str : words) {
            int i = 0, j = str.length() - 1, flag = 1;
            while (i < j) if (str[i++] != str[j--]) {flag = 0; break;}
            if (flag == 1) return str;
        };
        return "";
    };
};