class Solution {
public:
    int longestMountain(vector<int>& nums) {
        int n = nums.size(), best = 0, curr = 1;
        bool lookingForIncrease = 1;         
        
        for (int i = 1; i < n; i++) {
            if (lookingForIncrease) {
                if (nums[i] > nums[i - 1]) curr++;
                else if (nums[i] < nums[i - 1]) {
                    if (curr > 1) lookingForIncrease = 0, curr++, best = max(curr, best);
                } else curr = 1;
            } else {
                if (nums[i] < nums[i - 1]) {
                    curr++;
                    best = max(curr, best);
                } else if (nums[i] > nums[i - 1]) {
                    lookingForIncrease = 1, curr = 2;
                } else curr = 1;
            };
        };
        
        return best;
    };
};


/*

1 2 1 0 -1 3

*/