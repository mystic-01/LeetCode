class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto &word : words) count += (s.substr(0, word.size()) == word);
        return count;
    };
};