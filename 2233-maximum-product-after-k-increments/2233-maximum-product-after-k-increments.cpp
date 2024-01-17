class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        long product = 1, mod = 1e9 + 7;
        for (int &x : nums) pq.push(x);
        while (k) {
            int top = pq.top();
            pq.pop();
            pq.push(top + 1);
            --k;
        };
        while (!pq.empty()) {
            product = (product * pq.top()) % mod; 
            pq.pop();
        };
        return product;
    };
};