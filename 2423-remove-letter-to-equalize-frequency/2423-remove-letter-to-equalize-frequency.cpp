class Solution {
public:
    bool canMakeEqualFreq(int currFreq, int *freq, int *dp) {
        if (dp[currFreq] != -1) return dp[currFreq];
        
        int deletions = 0, nonZero = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                if (freq[i] >= currFreq) deletions += (freq[i] - currFreq);
                else deletions += freq[i]; 
                nonZero++;
            };
        };
        if (deletions == 0) return dp[currFreq] = (currFreq == 1 ? true : nonZero == 1);
        return dp[currFreq] = (deletions == 1);        
    };
    
    bool equalFrequency(string word) {
        int n = word.size(), freq[26] = {0}, dp[n + 1];
        for (int i = 0; i < n; i++) {
            freq[word[i] - 'a']++, dp[i] = -1;
        };
        
        bool ans = false;
        for (int i = 0; i < 26; i++) {
            if (freq[i]) ans = ans || canMakeEqualFreq(freq[i], freq, dp);
        };
        return ans;
    };
};
