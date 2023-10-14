class Solution {
public:
    int hammingDist(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            diff += (a[i] != b[i]);
        };
        return diff;
    };
    
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int i = 0, parity = groups[0], dp[n], maxDp = 0, maxDpIdx = -1, maxDpStringLen = -1;
        for (int i = n - 1; i >= 0; --i) {
            dp[i] = 1;
        };
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].size() == words[j].size() && groups[i] != groups[j] 
                    && hammingDist(words[i], words[j]) == 1) {
                    dp[i] = max(dp[i], 1 + dp[j]);    
                };
            };        
            if (dp[i] > maxDp) {
                maxDp = dp[i], maxDpIdx = i, maxDpStringLen = words[i].size();    
            };
        };

        for (int i = maxDpIdx, lastIdx = -1; i < n; ++i) {
            if (dp[i] == maxDp && words[i].size() == maxDpStringLen) {
                if (!ans.size() || (groups[i] != groups[lastIdx] 
                    && hammingDist(words[i], words[lastIdx]) == 1)) {
                    ans.push_back(words[i]);
                    --maxDp; 
                    lastIdx = i;
                };
            };
        };
        return ans;        
    };
};