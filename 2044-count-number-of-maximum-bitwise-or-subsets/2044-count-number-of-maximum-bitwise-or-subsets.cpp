class Solution {
public:
    void recurse(int idx, int orValue, int &best, int &count, vector<int> &nums) {
        if (idx == nums.size()) {
            if (orValue > best) best = orValue, count = 1;                            
            else if (orValue == best) count++;                            
            return;
        };
        
        recurse(idx + 1, orValue, best, count, nums);
        recurse(idx + 1, orValue | nums[idx], best, count, nums);        
    };
    
    int countMaxOrSubsets(vector<int>& nums) {
        int best = INT_MIN, count = 0;
        recurse(0, 0, best, count, nums);
        return count;
    };
};