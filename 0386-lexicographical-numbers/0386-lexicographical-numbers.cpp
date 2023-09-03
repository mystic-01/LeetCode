class Solution {
public:
    void recurse(int i, int &n, vector<int> &ans) {
        if (i > n) return;
        ans.push_back(i);
        recurse(i * 10, n, ans);
        if (i % 10 != 9) recurse(i + 1, n, ans);
    };
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        recurse(1, n, ans);
        return ans;
    };
};