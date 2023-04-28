class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int idx = 0;
        map<vector<int>, int> m;
        vector<vector<string>> ans;
        
        for (auto &str : strs) {
            vector<int> chars(26, 0);
            for (auto &x : str) chars[x - 'a']++;
            
            if (m.find(chars) == m.end()) {
                ans.push_back({}); 
                m[chars] = idx++;
            };
            
            ans[m[chars]].push_back(str);
        };
        
        return ans;
    };
};