class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int totalTrust[n + 1];
        for (int i = 0; i < n + 1; i++) totalTrust[i] = 0;
        for (int i = 0; i < trust.size(); i++) totalTrust[trust[i][0]]--, totalTrust[trust[i][1]]++;
        for (int i = 1; i < n + 1; i++) if (totalTrust[i] == n - 1) return i;
        return -1;
    };
};