class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        int n = nums.size(), diff = 0, best = 0;
        m[0] = -1;
        // What we really do here is, we increase diff if the value of nums[i] is one, otherwise we decrease it. 
        // Why? You may think. The reason is we are trying to find the difference between count of 1s and 0s. 
        // And if the same difference (between counts of 1s and 0s) has appeared in the past, then the length of 
        // array from that index till current index has the same no. of 1s and 0s, makes sense, right? 
        // So, that makes it a valid array and we test it's length against our best. But if we don't find the
        // current difference int the map then we just put it in the map for future use.
        // And m[0] = -1 is there because if difference is 0 at a particular index say 'x', then subarray from
        // 0 to 'x' would always a valid subarray, with length : x + 1 OR x - (-1) OR x - m[0] OR x - m[diff].
        for (auto i = 0; i < n; i++) {
            diff += nums[i] ? 1 : -1;
            if (m.find(diff) != m.end()) best = max(best, i - m[diff]);
            else m[diff] = i;
        };
        return best;
    };
};