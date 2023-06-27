class Solution {
public:
    struct comp {
        bool operator()(const vector<int> &v1, const vector<int> &v2) {
            return v1[0] + v1[1] < v2[0] + v2[1];                     
        };        
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        
        for (int &x : nums1) {
            for (int &y : nums2) {
                if (pq.size() < k) pq.push({x, y});
                else if (x + y < pq.top()[0] + pq.top()[1]) {
                    pq.push({x, y});
                    pq.pop();
                } else break;
            };        
        };
        
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        };
        
        return ans;
    };
};