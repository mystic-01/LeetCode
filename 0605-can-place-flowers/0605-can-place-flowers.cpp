class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int size = nums.size();
        for (auto i = 0; i < size; i++)
            if (nums[i] == 0 && (i - 1 < 0 || nums[i - 1] == 0) && (i + 1 >= size || nums[i + 1] == 0))
                nums[i] = 1, n--;

        return n <= 0;
    };
};