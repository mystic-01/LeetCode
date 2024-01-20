class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> ans;
        int size = rounds.size() - 1;
        if (rounds[0] <= rounds[size]) {
            for (int i = rounds[0]; i <= rounds[size]; ++i) {
                ans.push_back(i);
            };         
            return ans;
        };
        

        for (int i = 1; i <= rounds[size]; ++i) {
            ans.push_back(i);            
        };
        for (int i = rounds[0]; i <= n; ++i) {
            ans.push_back(i);
        };
        return ans;
    };
};