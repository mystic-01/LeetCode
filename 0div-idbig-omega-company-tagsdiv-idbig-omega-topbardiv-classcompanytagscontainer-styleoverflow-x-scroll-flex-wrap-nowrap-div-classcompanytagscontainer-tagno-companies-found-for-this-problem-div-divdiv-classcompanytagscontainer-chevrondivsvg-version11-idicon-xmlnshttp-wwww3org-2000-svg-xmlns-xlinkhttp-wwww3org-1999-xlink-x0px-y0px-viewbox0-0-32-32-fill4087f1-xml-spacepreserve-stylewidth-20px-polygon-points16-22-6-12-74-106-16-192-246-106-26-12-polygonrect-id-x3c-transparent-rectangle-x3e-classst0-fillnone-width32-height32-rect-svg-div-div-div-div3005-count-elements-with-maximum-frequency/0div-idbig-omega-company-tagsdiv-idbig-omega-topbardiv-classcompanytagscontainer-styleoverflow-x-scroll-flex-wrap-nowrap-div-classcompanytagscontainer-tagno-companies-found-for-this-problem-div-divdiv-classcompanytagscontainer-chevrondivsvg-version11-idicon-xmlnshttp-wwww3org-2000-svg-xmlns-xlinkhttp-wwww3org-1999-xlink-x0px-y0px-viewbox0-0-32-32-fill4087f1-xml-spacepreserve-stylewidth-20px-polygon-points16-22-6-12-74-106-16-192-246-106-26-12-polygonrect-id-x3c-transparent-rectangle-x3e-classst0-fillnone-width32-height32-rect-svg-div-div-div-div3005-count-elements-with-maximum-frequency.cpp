class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int m[101] = {0}, freq = 0, maxFreq = 0, count = 0;
        for (int &x : nums) {
            if (++m[x] > maxFreq) {
                maxFreq = m[x], count = 1;    
            } else if (m[x] == maxFreq) {
                ++count;
            };    
        };
        return count * maxFreq;
    };
};