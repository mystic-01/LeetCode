class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        for (int i = 0, j = 0; j < nums.size(); j++, i = j) {
            if (j % 2 != nums[j] % 2) {
                while (i < nums.size() && j % 2 != nums[i] % 2) i++;
                swap(nums[i++], nums[j]);
            };            
        };  
        return nums;
    };
};