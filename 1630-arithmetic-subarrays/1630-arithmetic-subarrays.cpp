class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int qSize = l.size(), n = nums.size();
        
        vector<bool> ans(qSize, true);    
        
        for (auto i = 0; i < qSize; i++) {
            int left = l[i], right = r[i], len = right - left + 1;
            int minE = *min_element(nums.begin() + left, nums.begin() + right + 1); 
            int maxE = *max_element(nums.begin() + left, nums.begin() + right + 1); 
            
            // ideal diff Between Two Elements
            int d = (maxE - minE) / (len - 1);
            
            if (minE == maxE) continue;
            else if ((maxE - minE) % (len - 1)) ans[i] = false;
            else {
                vector<bool> ap(len, false);
                for (auto j = left; j <= right; j++) {
                    int idx = (nums[j] - minE) / d;
                    if ((nums[j] - minE) % d || ap[idx]) {
                        ans[i] = false;
                        break;
                    } else ap[idx] = true;
                };
            };
        };
        
        return ans;
    };
};