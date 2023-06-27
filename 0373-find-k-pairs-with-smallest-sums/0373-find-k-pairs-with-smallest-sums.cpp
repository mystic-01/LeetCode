class Solution {
public:
    struct comp {
        bool operator()(const pair<int, int> &v1, const pair<int, int> &v2) {
            return v1.first + v1.second < v2.first + v2.second;                     
        };        
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        
        for (int &x : nums1) {
            for (int &y : nums2) {
                if (pq.size() < k) pq.push({x, y});
                else if (x + y < pq.top().first + pq.top().second) {
                    pq.push({x, y});
                    pq.pop();
                } else break;
            };        
        };
        
        while (!pq.empty()) {
            ans.push_back({pq.top().first, pq.top().second});
            pq.pop();
        };
        
        return ans;
    };
};