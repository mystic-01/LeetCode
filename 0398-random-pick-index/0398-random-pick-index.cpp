class Solution {
public:
    unordered_map<int, vector<int>> m;
    
    Solution(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            this->m[nums[i]].push_back(i);    
        };
    };
    
    int pick(int target) {
        int n = this->m[target].size(), random = rand() % n;
        return m[target][random];
    };
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */