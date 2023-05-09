class Solution {
public:
    int countAsterisks(string s) {
        int asterisks = 0, open = 0;
        for (auto &ch : s) {
            if (ch == '*' && open == 0) asterisks++;
            if (ch == '|') open = !open;
        };
        return asterisks;
    };
};