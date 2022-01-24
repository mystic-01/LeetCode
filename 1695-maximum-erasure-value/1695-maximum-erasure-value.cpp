// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         unordered_map<int, int> m;
//         int sum = 0, best = 0, right = 0;
//         for (auto right = 0; right < nums.size(); right++) {
//             if (m.find(nums[right]) != m.end()) sum -= m[nums[right]];
//             sum += nums[right];
//             cout << sum << " ";
//             m[nums[right]] = sum;
//             best = max(best, sum);
//         };

//         best = max(best, sum);

//         return best;
//     };
// };

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> sums;
        int n = nums.size(), best = 0, left = 0, prefixSum = 0;
        int sumToBeRemoved = 0;

        for (auto right = 0; right < n; right++) {
            if (m.find(nums[right]) != m.end()) {
                sumToBeRemoved = max(m[nums[right]], sums[nums[right]]);
                while (left < n && nums[left] != nums[right]) m.erase(nums[left++]);
                ++left;
            };
            prefixSum += nums[right];
            sums[nums[right]] = prefixSum;
            m[nums[right]] = prefixSum - sumToBeRemoved;

            best = max(best, m[nums[right]]);
        };
        return best;
    };
};