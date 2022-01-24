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
        
        unordered_map<int, int> prefix;
        
        int n = nums.size(), best = 0, left = 0, sum = 0;
        int sumToBeRemoved = 0;

        for (auto right = 0; right < n; right++) {
            if (prefix.find(nums[right]) != prefix.end()) {
                
                sumToBeRemoved = prefix[nums[right]];
                while (left < n && nums[left] != nums[right]) prefix.erase(nums[left++]);
                left++;
            
            };
            sum += nums[right];
            prefix[nums[right]] = sum;
            best = max(best, sum - sumToBeRemoved);
        };
        return best;
    };
};