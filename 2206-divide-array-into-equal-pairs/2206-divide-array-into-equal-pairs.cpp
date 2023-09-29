class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int m[501] = {0};
        for (int &x : nums) {
            m[x]++;            
        };
        for (int &it : m) {
            if (it % 2) return false;    
        };
        return true;
    };
};