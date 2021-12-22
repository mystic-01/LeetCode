class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        auto iterator = ruleKey == "color" ? 1 : (ruleKey == "name" ? 2 : 0) , count = 0; 
        for (auto i = 0; i < items.size(); i++) {
            if (items[i][iterator] == ruleValue)
                count++;
        };        
        return count;
    };
};