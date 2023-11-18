class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        set<int> s;
        unordered_map<int, int> next;        
        int triplets = 0;
        for (int &x : nums) {
            s.insert(x);             
        };
        for (auto &it : s) {
            if (s.find(it + diff) != s.end()) {
                if (next.find(it) == next.end()) {
                    next[it] = 1;
                };
                next[it + diff] += next[it] + 1;    
                next[it] = 1;
            };            
        };
        for (auto &it2 : next) {
            triplets += max(0, it2.second - 2);
        };
        return triplets;
    };
};
