class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for (int &x : nums) {
            count += x < k;   
        };
        return count;
    };
};