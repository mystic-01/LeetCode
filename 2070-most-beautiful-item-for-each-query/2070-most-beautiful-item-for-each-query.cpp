class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];            
    };    
    
    int lowerBound(int target, vector<vector<int>>& items) {
        int lo = 0, hi = items.size() - 1;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target == items[mid][0]) return mid;
            else if (target > items[mid][0]) lo = mid + 1;
            else hi = mid - 1;
        };
        
        return items[lo][0] <= target ? lo : lo - 1;
    };            
    
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), comp);
        
        int last = -1;
        
        for (auto &vec : items) {
            vec[1] = max(vec[1], last), last = max(last, vec[1]);
        };

        for (auto &q : queries) {
            int idx = lowerBound(q, items);
            q = idx < 0 ? 0 : items[idx][1];            
        };
        
        return queries;
    };
};