class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int triplets = 0;
        for (auto &it : nums) {
            if (it >= 2 * diff) {
                triplets += (find(begin(nums), end(nums), (it - diff)) != end(nums) 
                                  && find(begin(nums), end(nums), (it - 2 *diff)) != end(nums));
            };            
        };
        return triplets;
    };
};
