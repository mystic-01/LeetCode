class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n1 = s.length(), n2 = goal.length(), diff = 0, existsDuplicate = 0;
        
        if (n1 != n2) return false;
        
        string sTemp  = "", goalTemp = "";
        vector<int> v(26, 0);
        
        for (auto i = 0; i < n1; i++) {
            if (s[i] != goal[i]) {
                if (++diff > 2) return false;
                sTemp = s[i] + sTemp, goalTemp = goalTemp + goal[i];
            };    
            if (++v[s[i] - 'a'] == 2) existsDuplicate = 1;
        };
        
        return !diff ? existsDuplicate : sTemp == goalTemp;  
    };
};