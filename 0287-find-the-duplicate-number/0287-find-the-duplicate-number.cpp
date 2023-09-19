class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow], fast = nums[nums[fast]];            
        };
        fast = 0;
        while (slow != fast) {
            slow = nums[slow], fast = nums[fast];            
        };        
        return slow;
    };
};

/*

1->3->2->4
       |_|
*/