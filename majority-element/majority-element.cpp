class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int cMax = nums[0], cFreq  = m[nums[0]];
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]] > cFreq) {
                cMax = nums[i];
            }
        }
        return cMax;
    }
};