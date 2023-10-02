class Solution {
public:
    bool winnerOfGame(string nums) {
        int n = nums.size(), removeableA = 0, removeableB = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (nums[i] == 'A') {
                if (nums[i - 1] == 'A' && nums[i + 1] == 'A') {
                    ++removeableA;
                    // nums[i - 1] = '*'
                };
            } else if (nums[i] == 'B') {
                if (nums[i - 1] == 'B' && nums[i + 1] == 'B') {
                    ++removeableB;
                    // nums[i - 1] = '*'
                };
            };
        };
        return removeableA > removeableB;
    };
};


/*

ABBBAAA

*/