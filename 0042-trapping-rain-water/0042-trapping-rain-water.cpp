class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size(), water = 0, leftMax = -1, rightMax = -1, left = 0, right = n - 1;
        while (left <= right) {
            if (leftMax <= rightMax) {
                if (nums[left] >= leftMax) {
                    leftMax = nums[left++];                    
                } else {
                    water += (leftMax - nums[left++]);
                };
            } else {
                if (nums[right] >= rightMax) {
                    rightMax = nums[right--];                    
                } else {
                    water += (rightMax - nums[right--]);
                };                
            };                
        };
        return water;
    };
};