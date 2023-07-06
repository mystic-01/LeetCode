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
                    if (senders[i][j] > ans[j]) {
                        isSwapNeeded = 1;
                        break;
                    } else if (ans[j] > senders[i][j]) {
                        isSwapNeeded = 0;
                        break;
                    };
                };    
                switch (isSwapNeeded) {
                    case -1:
                        if (senders[i].size() > ans.size()) ans = senders[i];
                        break;
                    case 1:
                        ans = senders[i];
                        break;
                };
            };
        };
        return ans;
    };
};