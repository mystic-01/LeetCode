class Solution {
public:
    int maxScore(vector<int>& nums, int k) {        
        int n = nums.size(), m = n + 1, count = 0, best = 0;

        vector<int> left(n + 1, 0), right(n + 1, 0);
        
        int i = 1, j = n - 1;
        while (i <= k) {
            left[i] += (left[i - 1] + nums[i - 1]);           
            right[j] += (right[j + 1] + nums[j]);
            i++, j--;
        };
       
        i = k, j = n;
        while (i >= 0) {
            count = left[i--] + right[j--];
            best = max(best, count);
        };
        return best;
    };
};