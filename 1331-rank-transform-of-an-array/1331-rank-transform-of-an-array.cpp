class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int rank = 1; 
        map<int, int> m;
        
        for (auto &x : nums) m[x]++;        
        
        for (auto &i : m) i.second = rank++;
        
        for (auto &num : nums) num = m[num];
        
        return nums;
    };
};