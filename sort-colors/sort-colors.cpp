class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        int i = 0, j = length - 1;
        while (i < j) {
          if (nums[i] == 0) {
              i++;
          } else if (nums[j] == 0) {
              nums[j] = nums[i];
              nums[i] = 0;
              i++;
              j--;
          } else {
              j--;
          }
        };
        j = length - 1;
        while (i < j) {
          if (nums[j] == 2) {
              j--;
          } else if (nums[i] == 2) {
              nums[i] = nums[j];
              nums[j] = 2;
              i++;
              j--;
          } else {
              i++;
          }
        };
    };
};