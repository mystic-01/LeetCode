// class Solution {
// public:
//     int binarySearch(int l, int r, vector<int>& nums, int target) {
//         if (r >= l) {
//             int mid = l + (r - l) / 2;
//             if (target == nums[mid]) return mid;
//             else if (target < nums[mid]) return binarySearch(l, mid - 1, nums, target);
//             else return binarySearch(mid + 1, r, nums, target);
//         };  
//         return -1;
//     };
    
//     int findRotationIndex(vector<int>& nums) {
//         int lo = 0, hi = nums.size() - 1;
//         while (lo < hi) {
//             int mid = lo + (hi - lo) / 2;
//             if (nums[hi] > nums[mid]) hi = mid;
//             else lo = mid + 1;
//         };
//         return hi;
//     };
    
//     int search(vector<int>& nums, int target) {
//         int n = nums.size(), k = findRotationIndex(nums);
//         return target <= nums[n - 1] 
//             ? binarySearch(k, n - 1, nums, target) 
//             : binarySearch(0, k - 1, nums, target);
//     };
// };

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size(), lo = 0, hi = n - 1;
        
//         while (lo <= hi) {
//             int mid = lo + (hi - lo) / 2;
//             if (nums[mid] == target) {
//                 return mid;
//             // If left half is sorted.
//             } else if (nums[lo] <= nums[mid]) {
                
//                 // If target lies in this half.
//                 if (nums[lo] <= target && target < nums[mid]) {
//                     hi = mid - 1;
//                 } else {
//                     lo = mid + 1;
//                 };
                
//             // If right half is sorted.                
//             } else {
                
//                // If target lies in this half.
//                 if (nums[mid] < target && target <= nums[hi]) {
//                     lo = mid + 1;
//                 } else {
//                     hi = mid - 1;
//                 };
//             };
//         };
//         return -1;
//     };
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), lo =  0, hi = n - 1;
        
        while (lo <= hi) {
            int mid = (hi - lo) / 2 + lo;
            if (target == nums[mid]) {
                return mid;
            } else if (nums[mid] >= nums[lo]) {
                if (target < nums[mid] && target >= nums[lo]) hi = mid - 1;
                else lo = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
                else hi = mid - 1;                
            };
        };

        return -1;
    };
};












































