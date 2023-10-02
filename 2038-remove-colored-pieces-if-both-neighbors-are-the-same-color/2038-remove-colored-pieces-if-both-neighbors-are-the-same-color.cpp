class Solution {
public:
    bool winnerOfGame(string nums) {
        int n = nums.size(), diffBetweenAliceAndBob = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == nums[i - 1] && nums[i] == nums[i + 1]) {
                diffBetweenAliceAndBob += (nums[i] == 'A' ? 1 : -1);
            };
        };
        return diffBetweenAliceAndBob > 0;
    };
};


/*

ABBBAAA

*/