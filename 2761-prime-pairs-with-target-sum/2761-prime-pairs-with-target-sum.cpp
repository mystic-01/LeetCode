class Solution {
public:
    vector<vector<int>> findPrimePairs(int target) {
        vector<vector<int>> ans;
        vector<bool> numbers(target, 0);

        for (int i = 2; i < target; ++i) {
            if (!numbers[i]) {
                for (int j = 2; j * i < target; ++j) {
                    numbers[j * i] = 1;                                  
                };            
            };            
        };
        
        for (int i = 2; i <= target / 2; ++i) {
            if (!numbers[i] && target - i >= 2 && !numbers[target - i]) {
                ans.push_back({i, target - i});    
            };
        };        
        
        return ans;
    };
};