vector<int> cache;
int maxSize = 50000;

class Solution {
public:
    Solution() {
        recurse(1, maxSize, cache);        
    };
    
    void recurse(int i, int &n, vector<int> &cache) {
        if (i > n) return;
        cache.push_back(i);
        recurse(i * 10, n, cache);
        if (i % 10 != 9) recurse(i + 1, n, cache);
    };
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        for (int i = 0, j = 0; j < n; i++) {
            if (cache[i] <= n) ans[j++] = cache[i];
        };
        return ans;
    };
};