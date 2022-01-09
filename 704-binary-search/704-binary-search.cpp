class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) return mid;
            else if (target > nums[mid]) return binarySearch(nums, target, mid + 1, r);  
            else return binarySearch(nums, target, l, mid - 1);  
        }
        return -1;
    };
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);  
    };
};