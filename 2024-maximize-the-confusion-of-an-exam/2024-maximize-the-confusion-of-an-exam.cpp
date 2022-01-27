class Solution {
public:
    int maxConsecutiveAnswers(string nums, int k) {
        int n = nums.length(), best = 0, count = 0, left = 0;
        
        for (auto i = 0; i < n; i++) {
            if (nums[i] == 'F' && count++ >= k) while (left < n && nums[left++] != 'F');
            best = max(best, i + 1 - left);
        };
        
        count = 0, left = 0;
        for (auto i = 0; i < n; i++) {
            if (nums[i] == 'T' && count++ >= k) while (left < n && nums[left++] != 'T');
            best = max(best, i + 1 - left);
        };
        return best;
    };
};