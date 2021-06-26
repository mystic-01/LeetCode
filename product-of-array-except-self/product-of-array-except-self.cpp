class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto product = nums[0], zero = 0;
        vector<int> answer (nums.size(), 0);
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] != 0) product = product*nums[i];
            else zero++;
        };
        if (zero > 1) return answer;
        else if (zero) {
            for (auto i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) answer[i] = product;
            };
        }
        else {  
            for (auto i = 0; i < nums.size(); i++) {
                if (nums[i] != 0) answer[i] = product/nums[i];
                else answer[i] = product;
            };
        };
        return answer;
    };
};