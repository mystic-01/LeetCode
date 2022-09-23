class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0, canTakeOne = 1;
        unordered_map<char, int> m;
        
        for (auto &i : s) m[i]++;
        for (auto &x : m) {
            bool isOdd = x.second % 2;
            if (isOdd) {
                if (canTakeOne) len += x.second, canTakeOne = 0;
                else len += x.second - 1; 
            } else len += x.second;
        };
        return len;
    };
};