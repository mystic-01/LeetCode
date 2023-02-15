class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        int partitionSize = INT_MAX;
        for (auto &i : deck) m[i]++;
        for (auto &it : m) partitionSize = min(partitionSize, it.second); 
        
        for (auto &iter : m) {
            partitionSize = gcd(iter.second, partitionSize);
            if (partitionSize == 1) return false;
        };
        return true; 
    };
};