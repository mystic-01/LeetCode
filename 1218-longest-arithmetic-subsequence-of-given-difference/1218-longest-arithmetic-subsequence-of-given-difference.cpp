class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int best = 0;
        unordered_map<int, int> m;
        for (int &x : arr) m[x] = m.find(x - diff) != m.end() ? m[x - diff] + 1 : 1, best = max(best, m[x]);
        return best;
        
    };
};