class Solution {
public:
    int maxFreqOfSmallestchar (string s) {
        vector<int> v(26);
        for (auto i : s) v[i - 'a']++;                        
        for (auto i : v) if (i) return i;
        return 0;
    };
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int q1 = queries.size(), w1 = words.size(), it1 = 0, it2 = 0, count = 0;
        vector<int> q(q1, 0), w(w1, 0);
        
        for (auto s : queries) q[it1++] = maxFreqOfSmallestchar(s);
        for (auto s : words) w[it2++] = maxFreqOfSmallestchar(s);
        
        for (auto &num : q) {
            count = 0;
            for (auto word : w) if (num < word) count++;                                                
            num = count;
        };
        
        return q;
    };
};