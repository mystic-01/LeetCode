// class Solution {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
//         if (nums.size() == 1) return 0;
//         for (int i = 0; i < nums.size(); i++) {
//             if (i+k > nums.size()) return 0;
//             auto it = std::find(nums.begin()+i+1, nums.begin()+i+k, nums[i]);
//             if (it - nums.begin() != i) {
//                 if (nums[it - nums.begin()] == nums[i]) return 1;
//             };
//         };
//         return 0;
//     };
// };
            
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() ==1) return 0;
        for(auto i = 0; i< nums.size()-1;i++){
            auto limit = (i+1+k > nums.size()) ? nums.end() : nums.begin()+i+1+k;
            auto it = find(nums.begin()+i+1,limit,nums[i]);
            if(it != limit)
                 return 1;
        }
        return 0;
    }
};






















// cout << i << " : " << it-nums.begin() << " : " << nums.size() << endl;