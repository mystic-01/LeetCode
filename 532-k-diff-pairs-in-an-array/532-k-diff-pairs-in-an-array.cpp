class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> m;
        
        for (auto i : nums) m[i]++;            
        
        if (k != 0) {
            for (auto i : m) if (m.find(i.first + k) != m.end()) count++;
        } else {
            for (auto i : m) if (m[i.first] > 1) count++;                
        };
        return count;
    };
};