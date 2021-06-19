class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            
            std::vector<int>::iterator it;
            it = std::find (nums.begin() + i + 1, nums.end(), target - nums[i]);
                                std::cout << it - nums.begin() << " " << i << endl;
            if (it - nums.begin() < size) {
                if (nums[it - nums.begin()] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(it - nums.begin());
                    break;
                };
            };
        };                    
        return result;
    };
};