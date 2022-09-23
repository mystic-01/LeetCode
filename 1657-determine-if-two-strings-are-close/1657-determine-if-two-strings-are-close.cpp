class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        
        if (n1 != n2) return false;
        
        vector<int> v1(26, 0), v2(26, 0);

        for (auto i = 0; i < n1; i++) v1[word1[i] - 'a']++, v2[word2[i] - 'a']++;            
        
        for (auto i = 0; i < 26; i++) if ((v1[i] && !v2[i]) || (!v1[i] && v2[i])) return false;

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        for (auto i = 0; i < 26; i++) if (v1[i] != v2[i]) return false;
        
        return true;
    
    };
};