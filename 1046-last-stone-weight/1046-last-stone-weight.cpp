class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        int n = nums.size();
        
        priority_queue<int, vector<int>> pq;
        for (auto i = 0; i < n; i++) {
            pq.push(nums[i]);            
        };
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            pq.push(a - b);
        };
        return pq.top();
    };
};