class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";
        do {
            int mod =  columnNumber % 26;
            mod = mod == 0 ? 26 : mod;
            ans = char(mod + 64) + ans;
            columnNumber -= mod;
            columnNumber /= 26;
        } while (columnNumber);
        return ans;
    };
};