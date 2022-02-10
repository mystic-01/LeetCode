class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size(), low = 0, sum = 0, count = 0;
        for(auto i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k) sum -= nums[low++];
            if (i >= k - 1 && sum / k >= threshold) count++;
        };
        return count;
    };
};