class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string &s : operations) if (s[0] == '+' || s[s.size() - 1] == '+') x++; else x--;
        return x;
    };
};