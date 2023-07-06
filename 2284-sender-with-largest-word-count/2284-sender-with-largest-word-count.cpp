class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> m;
        int n = messages.size(), maxCount = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            int count = 1;
            for (char &x : messages[i]) if (x == ' ') count++;
            m[senders[i]] += count;
            
            if (m[senders[i]] > maxCount) ans = senders[i], maxCount = m[senders[i]];
            else if (m[senders[i]] == maxCount) {
                int isSwapNeeded = -1;
                for (int j = 0; j < senders[i].size() && j < ans.size(); j++) {
                    if (senders[i][j] != ans[j]) {
                        isSwapNeeded = (senders[i][j] > ans[j]);
                        break;
                    };
                };    
                if ((isSwapNeeded == -1 && senders[i].size() > ans.size()) || (isSwapNeeded == 1)) ans = senders[i];
            };
        };
        return ans;
    };
};