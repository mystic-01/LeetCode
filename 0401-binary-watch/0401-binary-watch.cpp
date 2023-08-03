class Solution {
private:
    bool isValidTime(pair<int, int> &ds) {
        return ds.first < 12 && ds.first >= 0 && ds.second < 60 && ds.second >= 0;    
    };
    
    int count = 0;
public:
    void recurse(int hIdx, int mIdx, int turnedOn, int *hours, int *minutes, set<string> &ans, pair<int, int> &ds, int (*dp)[64]) {
        if (turnedOn == 0) {
            if (!dp[ds.first][ds.second] && isValidTime(ds)) {
                count++;
                string hour = to_string(ds.first), minutes = to_string(ds.second);
                string curr = hour + ":" + (minutes.size() == 1 ? "0" : "") + minutes; 
                ans.insert(curr);
                dp[ds.first][ds.second] = 1;
            };
            return;
        };                
        if (hIdx >= 4 && mIdx >= 6) return;

        recurse(hIdx + 1, mIdx + 1, turnedOn, hours, minutes, ans, ds, dp);  
        
        if (hIdx < 4) {
            ds.first += hours[hIdx];
            recurse(hIdx + 1, mIdx, turnedOn - 1, hours, minutes, ans, ds, dp);
            ds.first -= hours[hIdx];
        };

        if (mIdx < 6) {
            ds.second += minutes[mIdx];
            recurse(hIdx, mIdx + 1, turnedOn - 1, hours, minutes, ans, ds, dp);
            ds.second -= minutes[mIdx];
        };
    };
    
    vector<string> readBinaryWatch(int &turnedOn) {
        vector<string> ans;
        set<string> ansSet;
        pair<int, int> ds;
        int hours[4] = {8, 4, 2, 1}, minutes[6] = {32, 16, 8, 4, 2, 1}, dp[16][64];
        
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 64; j++) {
                dp[i][j] = 0;    
            };
        };
        
        // count = 0;
        recurse(0, 0, turnedOn, hours, minutes, ansSet, ds, dp);
        
        for (auto &it : ansSet) ans.push_back(it);
        
        cout << count << "\n";
        return ans;
    };
};

/*

1
10
44
112
181
190
126
48
8
0
0

*/