// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for (auto i = 0; i < nums.size(); i++) {
//             if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) return 1;
//             m[nums[i]] = i; 
//         };
//         return 0;
//     };
// };

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (auto i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end()) return 1;
            s.insert(nums[i]);
        };
        return 0;
    };
};