class Solution {
public:
    struct arrayStruct {
        int arr[2] = {0, 0};
        arrayStruct(int &x, int &y) {
            arr[0] = x, arr[1] = y;
        };
    };
    
    struct comp {
        bool operator()(const arrayStruct &v1, const arrayStruct &v2) {
            return v1.arr[0] + v1.arr[1] < v2.arr[0] + v2.arr[1];                     
        };        
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        priority_queue<arrayStruct, vector<arrayStruct>, comp> pq;
        
        for (int &x : nums1) {
            for (int &y : nums2) {
                if (pq.size() < k) pq.push(arrayStruct(x, y));
                else if (x + y < pq.top().arr[0] + pq.top().arr[1]) {
                    pq.pop();
                    pq.push({x, y});
                } else break;
            };        
        };
        
        while (!pq.empty()) {
            ans.push_back({pq.top().arr[0], pq.top().arr[1]});
            pq.pop();
        };
        
        return ans;
    };
};