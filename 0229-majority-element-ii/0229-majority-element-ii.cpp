class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size(), goldenNum = n / 3 + 1;
        int cd1 = 2147483647, count1 = 0, cd2 = 2147483647, count2 = 0;        
        
        for (int i = 0; i < n; i++) {
            if (cd1 == nums[i]) {
                count1++;        
            } else if (cd2 == nums[i]) {
                count2++;  
            } else if (count2 == 0) {
                cd2 = nums[i], count2 = 1;                                
            } else if (count1 == 0) {
                cd1 = nums[i], count1 = 1;                                
            } else {
                count1--, count2--;    
            };
        };
        count1 = 0, count2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            count1 += (nums[i] == cd1);
            count2 += (nums[i] == cd2);
        };        
        if (count1 >= goldenNum) ans.push_back(cd1);
        if (count2 >= goldenNum) ans.push_back(cd2);
        return ans;
    };
};


/*

[3,4,5,6,3,6]

[1,2,1,2,1,2,1,3,3,3,3,3]

[4,3,6,3,6,6,6,3,3]

4 3
6 4
6 3
3 6
*/