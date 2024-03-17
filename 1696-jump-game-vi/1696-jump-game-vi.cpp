class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        for (int i = 0; i < n; ++i) {
            int currScore = nums[i] + (!dq.empty() ? nums[dq.front()] : 0);
            
            while (!dq.empty() && currScore > nums[dq.back()]) {
                dq.pop_back();    
            };
            nums[i] = currScore;
            dq.push_back(i);
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();    
            };
        };
        return nums[n - 1];
    };
};