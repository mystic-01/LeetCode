class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& nums) {
        int n = nums.size(), rank = 1; 
        map<int, int> m;
        
        for (auto i = 0; i < n; i++) m[nums[i]]++;        
        
        for (auto &x : m) x.second = rank++;
        
        for (auto i = 0; i < n; i++) nums[i] = m[nums[i]];
        
        return nums;
    };
};