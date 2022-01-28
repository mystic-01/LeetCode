class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n, 0);
        int i = 0, j = n - 1;
        while (i < j) ans[j--] = -1 * (ans[i++] = i + 1);                       
        return ans;
    };
};