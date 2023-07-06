class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trustReceived[n + 1];
        bool trustGiven[n + 1];
        for (int i = 0; i < n + 1; i++) trustReceived[i] = 0, trustGiven[i] = 0;
        for (int i = 0; i < trust.size(); i++) trustGiven[trust[i][0]] = 1, trustReceived[trust[i][1]]++;
        for (int i = 1; i < n + 1; i++) if (trustGiven[i] == 0 && trustReceived[i] == n - 1) return i;
        return -1;
    };
};