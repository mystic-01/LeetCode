class Solution {
public:
    string largestOddNumber(string num) {
        int lastOddIdx = -1;
        for (int i = num.size() - 1; i >= 0; --i) {
            if(int(num[i] - '0') % 2) {
                lastOddIdx = i;
                break;
            };
        };
        return num.substr(0, lastOddIdx + 1);
    };
};