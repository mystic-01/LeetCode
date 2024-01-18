class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int chars[26] = {0}, i = 1;        
        for (char &ch : s) {
            if (chars[ch - 'a'] == 0) chars[ch - 'a'] = i;
            else if (i - chars[ch - 'a'] - 1 != distance[ch - 'a']) return false;
            ++i;
        };
        return true;
    };
};