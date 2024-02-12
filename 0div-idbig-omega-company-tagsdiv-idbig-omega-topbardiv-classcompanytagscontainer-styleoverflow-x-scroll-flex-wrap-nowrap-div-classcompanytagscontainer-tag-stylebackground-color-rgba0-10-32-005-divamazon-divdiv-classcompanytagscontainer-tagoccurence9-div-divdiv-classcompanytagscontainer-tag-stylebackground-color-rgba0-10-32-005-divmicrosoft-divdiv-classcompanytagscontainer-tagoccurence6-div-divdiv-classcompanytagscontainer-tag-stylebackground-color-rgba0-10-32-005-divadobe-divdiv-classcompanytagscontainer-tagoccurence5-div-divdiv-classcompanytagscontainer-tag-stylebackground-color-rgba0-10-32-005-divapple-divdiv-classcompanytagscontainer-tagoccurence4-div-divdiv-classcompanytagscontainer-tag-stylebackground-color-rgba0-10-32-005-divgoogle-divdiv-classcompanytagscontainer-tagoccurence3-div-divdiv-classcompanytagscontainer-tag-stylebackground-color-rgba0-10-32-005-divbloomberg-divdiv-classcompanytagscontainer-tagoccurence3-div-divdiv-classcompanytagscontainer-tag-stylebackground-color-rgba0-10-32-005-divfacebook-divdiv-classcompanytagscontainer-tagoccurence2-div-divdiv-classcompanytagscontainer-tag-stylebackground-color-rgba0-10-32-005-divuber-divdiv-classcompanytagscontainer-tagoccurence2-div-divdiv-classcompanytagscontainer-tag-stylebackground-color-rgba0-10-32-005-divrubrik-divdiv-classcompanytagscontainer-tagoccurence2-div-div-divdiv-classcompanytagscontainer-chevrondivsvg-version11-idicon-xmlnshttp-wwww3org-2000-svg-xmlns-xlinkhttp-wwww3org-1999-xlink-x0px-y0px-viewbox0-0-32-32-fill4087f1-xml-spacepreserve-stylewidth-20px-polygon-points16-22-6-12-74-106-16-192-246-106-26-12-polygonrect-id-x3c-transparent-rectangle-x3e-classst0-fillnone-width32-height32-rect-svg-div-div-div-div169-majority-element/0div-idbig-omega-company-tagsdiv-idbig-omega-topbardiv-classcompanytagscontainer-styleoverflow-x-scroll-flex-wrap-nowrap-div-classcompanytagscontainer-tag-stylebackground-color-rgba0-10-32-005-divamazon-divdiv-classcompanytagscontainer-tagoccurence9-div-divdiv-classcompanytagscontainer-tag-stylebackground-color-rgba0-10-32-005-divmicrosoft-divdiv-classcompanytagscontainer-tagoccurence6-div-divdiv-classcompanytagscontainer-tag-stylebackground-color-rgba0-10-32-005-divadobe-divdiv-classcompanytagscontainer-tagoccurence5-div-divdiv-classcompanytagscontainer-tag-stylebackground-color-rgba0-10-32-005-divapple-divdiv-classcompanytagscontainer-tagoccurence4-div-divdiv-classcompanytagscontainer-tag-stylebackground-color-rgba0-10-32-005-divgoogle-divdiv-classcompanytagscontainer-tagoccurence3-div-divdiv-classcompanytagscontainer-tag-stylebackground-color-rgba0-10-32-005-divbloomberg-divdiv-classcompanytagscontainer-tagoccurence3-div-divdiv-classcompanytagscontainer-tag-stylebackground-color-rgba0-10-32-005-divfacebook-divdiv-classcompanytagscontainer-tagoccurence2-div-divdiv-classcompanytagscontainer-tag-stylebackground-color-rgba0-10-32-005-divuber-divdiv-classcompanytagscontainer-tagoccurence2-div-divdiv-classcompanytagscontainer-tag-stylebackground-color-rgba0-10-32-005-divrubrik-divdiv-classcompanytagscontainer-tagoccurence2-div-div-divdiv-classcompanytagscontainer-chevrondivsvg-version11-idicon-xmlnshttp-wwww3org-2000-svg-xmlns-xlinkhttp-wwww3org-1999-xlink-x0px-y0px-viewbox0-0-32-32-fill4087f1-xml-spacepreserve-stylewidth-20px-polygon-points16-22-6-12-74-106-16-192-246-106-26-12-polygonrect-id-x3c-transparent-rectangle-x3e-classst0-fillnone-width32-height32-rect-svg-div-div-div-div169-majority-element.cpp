class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cd = nums[0], count = 1;
        for (int i = 1; i <  nums.size(); ++i) {
            if (count == 0) {
                cd = nums[i];    
            };
            if (nums[i] == cd) {
                ++count;                
            } else {
                --count;
            };
        };
        return cd;
    };
};