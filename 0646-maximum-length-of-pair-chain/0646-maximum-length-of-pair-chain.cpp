class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& nums) {
        auto comp = [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        };
        
        sort(nums.begin(), nums.end(), comp);        
        
        int end = INT_MIN, count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i][0] > end) end = nums[i][1], count++;
        };
        return count;
    };
};