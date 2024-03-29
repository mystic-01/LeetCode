class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(), rangeMin = -1e9, rangeMax = 1e9;
        multiset<pair<int, pair<int, int>>> ms;
        
        for (int i = 0; i < n; ++i) {
            ms.insert({nums[i][0], {0, i}});  
        };
        
        while (!ms.empty()) {
            auto start = ms.begin();
            auto end = ms.rbegin();
            int currMin = start->first, currMax = end->first;
            if (currMax - currMin < rangeMax - rangeMin) {
                rangeMin = currMin, rangeMax = currMax;                            
            };
            
            int idx = start->second.first, arrIdx = start->second.second; 
            ms.erase(start);
            
            if (idx == nums[arrIdx].size() - 1) {
                break;
            } else {
                ms.insert({nums[arrIdx][idx + 1], {idx + 1, arrIdx}});                  
            };
        };
        return {rangeMin, rangeMax};
    };
};