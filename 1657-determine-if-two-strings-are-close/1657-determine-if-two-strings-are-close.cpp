class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        
        if (n1 != n2) return false;
        
        int v1[26] = {0}, v2[26] = {0};

        // To map all the characters of both the words.
        for (auto i = 0; i < n1; i++) v1[word1[i] - 'a']++, v2[word2[i] - 'a']++;            

        // To check whether the two words contain the "same set of characters" or not.
        for (auto i = 0; i < 26; i++) if ((v1[i] && !v2[i]) || (!v1[i] && v2[i])) return false;

        // To get all the non zero frequencies sorted in the end.        
        sort(v1, v1 + 26);
        sort(v2, v2 + 26);

        // To check whether the two words contain the "same set of frequencies" or not.
        for (auto i = 0; i < 26; i++) if (v1[i] != v2[i]) return false;
        
        return true;
    
    };
};