class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int, int> next;        
        int triplets = 0;
        for (auto &it : nums) {
            if (find(begin(nums), end(nums), it + diff) != end(nums)) {
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
