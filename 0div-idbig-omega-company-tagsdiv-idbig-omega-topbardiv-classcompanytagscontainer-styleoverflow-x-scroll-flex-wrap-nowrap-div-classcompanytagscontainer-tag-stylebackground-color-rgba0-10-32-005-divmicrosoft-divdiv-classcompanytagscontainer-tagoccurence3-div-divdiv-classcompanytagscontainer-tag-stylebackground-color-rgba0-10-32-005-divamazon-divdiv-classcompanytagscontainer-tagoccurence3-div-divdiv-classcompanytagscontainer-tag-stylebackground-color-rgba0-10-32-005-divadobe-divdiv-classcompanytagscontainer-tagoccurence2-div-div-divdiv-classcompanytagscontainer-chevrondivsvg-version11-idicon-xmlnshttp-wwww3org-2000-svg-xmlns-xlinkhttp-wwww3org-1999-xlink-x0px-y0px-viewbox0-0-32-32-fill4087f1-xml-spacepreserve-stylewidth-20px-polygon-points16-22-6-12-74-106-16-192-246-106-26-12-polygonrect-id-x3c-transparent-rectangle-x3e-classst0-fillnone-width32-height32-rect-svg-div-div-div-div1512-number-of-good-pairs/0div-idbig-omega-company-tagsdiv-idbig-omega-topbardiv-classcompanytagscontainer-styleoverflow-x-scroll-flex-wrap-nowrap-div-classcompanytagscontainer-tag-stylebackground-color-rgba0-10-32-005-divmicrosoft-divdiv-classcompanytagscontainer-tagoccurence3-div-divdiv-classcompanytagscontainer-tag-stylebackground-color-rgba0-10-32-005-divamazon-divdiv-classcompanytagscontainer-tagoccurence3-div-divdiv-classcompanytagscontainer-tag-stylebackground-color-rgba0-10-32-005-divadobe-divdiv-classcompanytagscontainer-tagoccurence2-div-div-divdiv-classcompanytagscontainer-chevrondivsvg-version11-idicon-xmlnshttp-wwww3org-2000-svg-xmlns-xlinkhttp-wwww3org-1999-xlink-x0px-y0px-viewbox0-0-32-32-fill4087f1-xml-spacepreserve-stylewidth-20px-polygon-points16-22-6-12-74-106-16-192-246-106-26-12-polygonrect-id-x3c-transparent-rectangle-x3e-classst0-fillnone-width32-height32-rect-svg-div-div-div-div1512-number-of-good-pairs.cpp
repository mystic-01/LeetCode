class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {0}, goodPairs = 0;
        for (int &x : nums) {
            goodPairs += freq[x]++;    
        };
        return goodPairs;
    };
};