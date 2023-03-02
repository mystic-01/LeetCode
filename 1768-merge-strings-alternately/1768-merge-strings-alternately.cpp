class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n1 = word1.size(), n2 = word2.size(), i = 0, j = 0;
        
        while (i < n1 && j < n2) ans = ans + word1[i++] + word2[j++];    
        while (i < n1) ans += word1[i++];    
        while (j < n2) ans += word2[j++];    
        
        return ans;
    };
};