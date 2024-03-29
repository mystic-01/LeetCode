class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> medians(n - k + 1);
        multiset<int> ms(begin(nums), begin(nums) + k);
        auto mid = next(begin(ms), k / 2);

        for (int i = k; ; ++i) {
            medians[i - k] = ((long long)*(mid) + *prev(mid, k % 2 == 0)) / 2.0;            
            if (i == n) {
                break;    
            };
            ms.insert(nums[i]);
            if (nums[i] < *mid) {
                --mid;
            };
            if (nums[i - k] <= *mid) {
                ++mid;
            };
            ms.erase(ms.find(nums[i - k]));
        };
        return medians;
    };
};
