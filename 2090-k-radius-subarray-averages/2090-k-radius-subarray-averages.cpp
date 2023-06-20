class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size(), front = 0, rear = k, deno = 2 * k + 1;
        long runningSum = 0;

        vector<int> ans(size, -1);
        if (size < k) return ans;

        for (auto i = 0; i < size; i++) {
            if (i - k >= 0) {
                if (size - i <= k) break;
                if (i - k == 0) {
                    // Add numbers from first valid number to next 'k' numbers. 
                    for (auto j = 0; j <= k; j++) runningSum += nums[rear++];
                } else {
                    // Pop from front, Add from rear for rest all until (size - i < k).
                    runningSum += nums[rear++];
                    runningSum -= nums[front++];
                };                
                ans[i] = runningSum / deno;
            } else runningSum += nums[i];
        };
        return ans;
    };
};