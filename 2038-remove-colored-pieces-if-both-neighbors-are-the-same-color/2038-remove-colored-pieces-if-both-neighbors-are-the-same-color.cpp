class Solution {
public:
    bool winnerOfGame(string nums) {
        int n = nums.size(), canAliceRemove = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i + 1]) {
                canAliceRemove += (nums[i] == 'A' ? 1 : -1);
            };
        };
        return canAliceRemove > 0;
    };
};