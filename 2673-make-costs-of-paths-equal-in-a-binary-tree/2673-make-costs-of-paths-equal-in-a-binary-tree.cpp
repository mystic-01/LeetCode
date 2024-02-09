class Solution {
public:
    int minIncrements(int n, vector<int>& nums) {
        int inc = 0;
        
        auto left = [](const int &i) {
            return 2 * i + 1;    
        }; 
        auto right = [](const int &i) {
            return 2 * i + 2;    
        };         
            
        for (auto i = n - 1; i >= 0; --i) {
            int diffBetweenChildren = 0;
            if (left(i) < n && right(i) < n) {
                diffBetweenChildren = abs(nums[left(i)] - nums[right(i)]);                    
                nums[i] += max(nums[left(i)], nums[right(i)]);                    
                inc += diffBetweenChildren;
            };
        };
        
        return inc;
    };
};