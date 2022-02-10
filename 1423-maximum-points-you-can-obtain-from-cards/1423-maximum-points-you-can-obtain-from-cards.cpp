class Solution {
public:
    int maxScore(vector<int>& nums, int k) {        
        int n = nums.size(), m = n + 1, count = 0, best = 0;

        vector<int> left(k + 1, 0), right(k + 1, 0);
        
        int i = 1, j = k - 1;
        while (i <= k) {
            left[i] += (left[i - 1] + nums[i - 1]);           
            right[j] += (right[j + 1] + nums[n - i]);
            i++, j--;
        };
       
        i = 0;
        while (i <= k) {
            count = left[i] + right[i]; i++;
            best = max(best, count);
        };
        return best;
    };
};