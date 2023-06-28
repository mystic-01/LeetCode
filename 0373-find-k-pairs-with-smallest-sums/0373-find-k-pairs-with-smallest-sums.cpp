// Min heap Solution (Utilises the fact that the arrays are sorted) TC = O(k * logn)  

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;
        
        auto comp = [&nums1, &nums2](pair<int, int> &v1, pair<int, int> &v2) {
            return nums1[v1.first] + nums2[v1.second] > nums1[v2.first] + nums2[v2.second];                     
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        pq.emplace(0, 0);
        
        while (k-- && pq.size()) {
            auto p = pq.top();
            pq.pop();
            ans.push_back({nums1[p.first], nums2[p.second]});
            if (p.second + 1 < n2) pq.emplace(p.first, p.second + 1);
            if (p.second == 0 && p.first + 1 < n1) pq.emplace(p.first + 1, p.second);
        };
        
        return ans;
    };
};


/*

3  5  7
4  6  8
4  6  8

00 01 02



*/

/*
Max Heap solution TC = O(n^2)

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

*/