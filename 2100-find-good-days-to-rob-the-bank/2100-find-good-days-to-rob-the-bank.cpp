class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size(), incCount = 0, decCount = 0, lastInc = 0, lastDec = 1;
        vector<int> inc(n, 0), dec(n, 0), ans;
        for (int i = 0; i < n - 1; i++)
            if (security[i + 1] >= security[i]) {
                incCount++;
            } else {
                for (int j = lastInc; j <= i; j++) {
                    inc[j] = incCount--;
                };
                incCount = 0;
                lastInc = i + 1;
            };
        for (int j = lastInc; j <= n - 1; j++) inc[j] = incCount--;
        for (int i = 1; i < n; i++)
            if (security[i - 1] >= security[i]) {
                decCount++;
            } else {
                for (int j = i - 1; j >= lastDec; j--) {
                    dec[j] = decCount--;
                };
                decCount = 0;
                lastDec = i;
            };        
        for (int j = n - 1; j >= lastDec; j--) dec[j] = decCount--;
        for (int i = time; i < n - time; i++) if (inc[i] >= time && dec[i] >= time) ans.push_back(i);
        return ans;
    };
};