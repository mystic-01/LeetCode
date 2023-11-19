class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {        
        int n = nums.size(), pairs = 0;
        unordered_map<int, int> m;
        
        for (int &x : nums) {
            ++m[x];    
        };
        for (auto &it : m) {
            if (m.find(it.first - k) != m.end()) {
                pairs += m[it.first] * m[it.first - k];   
            };    
            if (m.find(it.first + k) != m.end()) {
                pairs += m[it.first] * m[it.first + k];  
            };                
            m[it.first] = 0;
        };
        
        return pairs;
    };
};