class Solution {
public:
    int longestIdealString(string s, int k) {
        int score[26] = {0}, ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int localMax = 0, idx = s[i] - 'a';
            for (int j = -k; j <= k; ++j) {
                if (idx + j >= 0 && idx + j < 26) {
                    localMax = max(localMax, score[idx + j]);                        
                };
            };  
            score[idx] = localMax + 1, ans = max(ans, score[idx]);
        };
        return ans;
    };
};