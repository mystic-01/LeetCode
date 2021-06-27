class Solution {
public:
    int search(vector<int>& nums, int target) {
      int l = 0, u = nums.size()-1;
        while (true) {
            int mid = (l + u) / 2;
            if (l > u) {
              return -1;  
            }
            if (nums[mid] == target) {
              return mid;  
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
            };
            
        };
        return -1;
    };
};