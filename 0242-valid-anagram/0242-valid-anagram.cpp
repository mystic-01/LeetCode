class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for (char &ch : s) ++freq[ch - 'a'];
        for (char &ch2 : t) --freq[ch2 - 'a'];
        for (int &x : freq) if (x) return false;
        return true;
    };
};