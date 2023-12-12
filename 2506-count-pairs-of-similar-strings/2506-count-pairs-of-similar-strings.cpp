class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        map<vector<bool>, int> m;
        for (string &str : words) {
            vector<bool> freq(26, false);
            for (char &ch : str) {
                freq[ch - 'a'] = true;
            };    
            if (++m[freq] > 1) ans += (m[freq] - 1); 
        };
        return ans;
    };
};