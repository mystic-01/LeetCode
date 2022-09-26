class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        map<int, set<int>> m;
        
        for (auto &str : equations) {
            int first = str[0] - 'a' + 1, second = str[3] - 'a' + 1;
            if (first == second) {
                if (str[1] == '=') continue;
                else return false;
            };
            if (str[1] == '=') m[first].insert(second), m[second].insert(first);        
            else m[first].insert(-1 * second), m[second].insert(-1 * first);  
        };
        // Fix this!!!
        for (auto &it : m) {
            for (auto &x : it.second) if (x > 0) it.second.insert(m[x].begin(), m[x].end());        
            if (it.second.count(-1 * it.first)) return false;    
        };
        for (auto &it : m) {
            for (auto &x : it.second) if (x > 0) it.second.insert(m[x].begin(), m[x].end());        
            if (it.second.count(-1 * it.first)) return false;    
        };
        
        return true;
    };
};