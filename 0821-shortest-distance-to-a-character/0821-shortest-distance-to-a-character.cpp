class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size(), i = 0;
        vector<int> ans(n, 0), indexes;
        for (char &ch : s) {
            if (ch == c) indexes.push_back(i);
            ++i;
        };
        int j = 0, k = 0;
        for (char &ch : s) {
            ans[j] = abs(indexes[k] - j);
            while (k + 1 < indexes.size() && abs(indexes[k + 1] - j) < ans[j]) ans[j] = abs(indexes[++k] - j);
            ++j;
        };
        return ans;
    };
};