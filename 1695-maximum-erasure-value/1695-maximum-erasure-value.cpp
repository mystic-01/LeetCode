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
        int n = nums.size(), best = 0, left = 0, sum = 0, sumToBeRemoved = 0;
        
        for (auto i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end()) {
                sumToBeRemoved = max(sumToBeRemoved, m[nums[i]]);
            };
            sum += nums[i];
            m[nums[i]] = sum;
            best = max(best, sum - sumToBeRemoved);
        };
        return best;
    };
};