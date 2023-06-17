class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        set<int> s;
        
        for (auto &i : nums) {
            if (s.size() < 3) s.insert(i);
            else break;
        };
        auto it = s.begin();
        return s.size() == 3 ? *(++it) : -1;
    };
};