class Solution {
public:
    int distanceBetweenBusStops(vector<int>& nums, int start, int dest) {
        int n = nums.size(), right = 0, left = 0;
        for (int i = start; (i % n) != dest; ++i) {
            right += nums[i % n];
        };
        for (int i = dest; (i % n) != start; ++i) {
            left += nums[i % n];
        };
        return min(right, left);
    };
};