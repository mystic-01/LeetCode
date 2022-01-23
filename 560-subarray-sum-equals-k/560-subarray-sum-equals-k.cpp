class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> m;
        m[sum]++;
        for (auto i : nums) {
            sum += i;
            if (m.find(sum - k) != m.end()) count += m[sum - k];
            m[sum]++;  
        }; 
        return count;
    };
};