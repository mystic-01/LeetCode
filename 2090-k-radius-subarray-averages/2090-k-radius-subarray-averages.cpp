class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size(), front = 0, rear = 0, deno = 2 * k + 1;
        long long runningSum = 0;
        vector<int> ans(size, -1);
        if (size < k) return ans;

        for (auto i = 0; i < size; i++) {
            if (i - k == 0 && size - i > k) {
                runningSum += nums[i];                
                rear = i + 1;
                int addCount = k;
                while (addCount--) runningSum += nums[rear++];
                ans[i] = runningSum / deno;
            } else if (i - k > 0 && size - i > k) {
                runningSum += nums[rear++];
                runningSum -= nums[front++];
                ans[i] = runningSum / deno;
            } else runningSum += nums[i];
        };

        return ans;
    };
};