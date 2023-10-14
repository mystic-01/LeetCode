class Solution {
public:
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        for (int i = 0, parity = groups[0]; i < n;) {
            string  curr = "";
            while (i < n && parity == groups[i]) {
                if (words[i].size() > curr.size()) {
                    curr = words[i];    
                };
                ++i;
            };
            ans.push_back(curr);
            if (i < n) parity = groups[i];
        };
        return ans;
    };
};