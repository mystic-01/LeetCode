class Solution {
public:
    string maxFreqOfSmallestchar (string s) {
        int count = 0;
        char small = 'z';
        for (auto i : s) if (i < small) small = i;                        
        for (auto i : s) if (i == small) count++;
        return to_string(count);
    };
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int q1 = queries.size(), it = 0, count = 0;
        
        vector<int> ans(q1, 0);
        for (auto &q : queries) q = maxFreqOfSmallestchar(q);
        for (auto &w : words) w = maxFreqOfSmallestchar(w);
        
        for (auto q2 : queries) {
            count = 0;
            for (auto w2 : words) if (stoi(q2) < stoi(w2)) count++;
            ans[it++] = count;
        };
        return ans;
    };
};