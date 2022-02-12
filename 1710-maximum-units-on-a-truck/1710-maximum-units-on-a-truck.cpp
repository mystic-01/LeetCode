class Solution {
public:
    int maximumUnits(vector<vector<int>>& nums, int truckSize) {
        for (auto i = 0; i < nums.size(); i++) swap(nums[i][0], nums[i][1]);   
        sort(nums.rbegin(), nums.rend());
        
        int count = 0;
        for (auto box : nums) {
            if (truckSize <= box[1]) {
                count += (truckSize * box[0]);
                break;
            };
            count += (box[1] * box[0]);
            truckSize -= box[1];
        };
        return count;
    };
};