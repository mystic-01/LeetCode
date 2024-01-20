class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for (char &ch : s) {
            ones += (ch == '1');
        };
        for (char &ch2 : s) {
            if (ones > 1) ch2 = '1', --ones;
            else ch2 = '0';
        };        
        s[s.size() - 1] = '1';
        return s;
    };
};