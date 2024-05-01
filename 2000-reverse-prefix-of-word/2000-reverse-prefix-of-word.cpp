class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        for (char &x : word) {
            ++i;
            if (x == ch) {
                break;    
            };    
        };
        if (word[i - 1] == ch) {
            reverse(begin(word), begin(word) + i);    
        };
        return word;
    };
};