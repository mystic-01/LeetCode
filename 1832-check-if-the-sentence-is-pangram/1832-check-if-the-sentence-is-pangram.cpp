class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool chars[26] = {0};
        for (char &ch : sentence) chars[ch - 'a'] = 1;
        return accumulate(chars, chars + 26, 0) == 26;
    };
};