class Solution {
public:
    string decodeMessage(string &key, string &message) {
        unordered_map<char, char> m;
        bool chars[26] = {0};
        char start = 'a';
        for (char &ch : key) {
            if (ch != ' ' && chars[ch - 'a'] == 0) {
                m[ch] = start++, chars[ch - 'a'] = 1;
            };
        };
        
        for (char &character : message) {
            if (character != ' ') {
                character = m[character];
            };
        };
        return message;
    };
};