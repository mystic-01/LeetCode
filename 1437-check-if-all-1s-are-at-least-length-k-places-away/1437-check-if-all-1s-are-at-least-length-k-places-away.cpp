class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = 0, gotOne = 0;
        for (int &x : nums) {
            if (gotOne) {
                if (x == 1) {
                    if (dist < k) return false;
                    else dist = 0;
                } else dist++;
            } else if (x) gotOne = 1;    
        };         
        return true;
    };
};