class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> m;
        for (auto &i : deck) m[i]++;

        int partitionSize = m[deck[0]];
        for (auto &iter : m) if ((partitionSize = gcd(iter.second, partitionSize)) == 1) return false;
        return true; 
    };
};