class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();        
        for (auto i = 0; i + 1 < n; i++) if (nums[i] > nums[i + 1]) return i;            
        return n - 1;
    };
};