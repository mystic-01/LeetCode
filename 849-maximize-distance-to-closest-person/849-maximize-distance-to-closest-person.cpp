// class Solution {
// public:
//     int maxDistToClosest(vector<int>& nums) {
//         int n = nums.size(), lastOne = -1e7, best = -1e7;
//         vector<int> v(n, -1e7);
//         for (auto i = 0; i < n; i++) {
//             if (nums[i]) lastOne = i;
//             else {
//                 if (lastOne != -1e7) v[i] = i - lastOne;
//                 else v[i] = 1e7;
//             };
//         };
//         lastOne = 1e7;
//         for (auto i = n - 1; i >= 0; i--) {
//             if (nums[i]) lastOne = i;
//             else v[i] = min(v[i], lastOne - i);
//             best = max(best, v[i]);
//         };
//         return best;
//     };
// };

class Solution {
public:
    int maxDistToClosest(vector<int>& nums) {
        int n = nums.size(), zeros = 0, best = INT_MIN;
        for (auto i = 0; i < n; i++) {
            if (nums[i]) zeros = 0;
            else {
                zeros++;
                best = max(best, (zeros + 1) / 2);
            };
        };
        
        zeros = 0;
        for (auto i = n - 1; i >= 0; i--) {
            if (nums[i]) break;
            zeros++;
            best = max(best, zeros);
        };
        
        zeros = 0;
        for (auto i = 0; i < n; i++) {
            if (nums[i]) break;
            zeros++;
            best = max(best, zeros);
        };
        return best;
    };
};