class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = 0, dec = 0;
        
        for (auto i = 1; i < nums.size(); i++) 
            nums[i] < nums[i - 1] ? dec = 1 : nums[i] > nums[i - 1]  ? inc = 1 : inc = inc;
            
        return (inc && !dec) || (!inc && dec) || (!inc && !dec);
    };
};