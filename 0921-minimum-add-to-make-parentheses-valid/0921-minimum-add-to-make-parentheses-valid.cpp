class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0, add = 0;
        for (char &ch : s) {
            if (ch == ')') {
                if (open) --open;
                else ++add;
            } else {
                ++open;
            };
        };
        return add + open;
    };
};