class Solution {
public:
    int minimumTime(string nums) {
        int n = nums.size(), count = 0;
        vector<int> left(n, 0), right(n, 0);
        
        if (nums[0] == '1') left[0] = 1;
        if (nums[n - 1] == '1') right[n - 1] = 1;
        
        
        for (auto i = 1; i < n; i++)
            left[i] = (nums[i] == '1') ? min(left[i - 1] + 2, i + 1) : left[i - 1]; 
        
        for (auto i = n - 2; i >= 0; i--)
            right[i] = (nums[i] == '1') ? min(right[i + 1] + 2, n - i) : right[i + 1]; 
        
        count = min(left[n - 1], right[0]);
        for (auto i = 0; i + 1 < n; i++)
            count = min(count, left[i] + right[i + 1]);

        return count;
    };
};