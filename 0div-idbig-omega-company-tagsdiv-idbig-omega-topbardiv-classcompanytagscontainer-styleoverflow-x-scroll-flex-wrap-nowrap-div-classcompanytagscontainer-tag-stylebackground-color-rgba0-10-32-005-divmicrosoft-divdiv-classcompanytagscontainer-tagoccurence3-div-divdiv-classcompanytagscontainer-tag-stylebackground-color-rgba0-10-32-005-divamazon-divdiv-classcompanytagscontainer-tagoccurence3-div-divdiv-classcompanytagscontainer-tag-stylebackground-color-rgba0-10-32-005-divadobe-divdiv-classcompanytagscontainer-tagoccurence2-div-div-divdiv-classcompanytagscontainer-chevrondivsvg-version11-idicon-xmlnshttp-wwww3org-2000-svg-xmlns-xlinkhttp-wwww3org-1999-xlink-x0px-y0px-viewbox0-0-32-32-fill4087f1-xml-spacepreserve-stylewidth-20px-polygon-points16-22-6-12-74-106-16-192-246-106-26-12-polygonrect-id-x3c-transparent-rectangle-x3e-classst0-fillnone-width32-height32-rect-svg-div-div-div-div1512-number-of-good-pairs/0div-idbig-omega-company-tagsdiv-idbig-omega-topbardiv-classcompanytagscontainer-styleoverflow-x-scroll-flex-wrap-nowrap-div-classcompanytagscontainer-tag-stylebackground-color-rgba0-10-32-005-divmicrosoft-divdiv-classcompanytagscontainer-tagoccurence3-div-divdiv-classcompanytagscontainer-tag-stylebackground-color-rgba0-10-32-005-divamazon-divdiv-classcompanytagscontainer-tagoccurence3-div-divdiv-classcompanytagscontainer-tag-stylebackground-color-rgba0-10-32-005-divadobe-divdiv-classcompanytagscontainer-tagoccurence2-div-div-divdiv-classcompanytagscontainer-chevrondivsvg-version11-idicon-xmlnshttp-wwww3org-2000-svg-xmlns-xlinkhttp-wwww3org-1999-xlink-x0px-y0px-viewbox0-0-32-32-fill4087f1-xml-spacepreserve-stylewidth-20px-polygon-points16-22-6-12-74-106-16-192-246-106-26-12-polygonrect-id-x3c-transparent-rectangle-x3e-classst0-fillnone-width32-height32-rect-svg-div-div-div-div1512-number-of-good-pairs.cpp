class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {0}, goodPairs = 0;
        for (int &x : nums) {
            ++freq[x];    
        };
        for (int &f : freq) {
            goodPairs += (((f - 1) * f) / 2);            
        };
        return goodPairs;
    };
};