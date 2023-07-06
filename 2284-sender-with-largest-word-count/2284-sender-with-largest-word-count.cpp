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
            else if (m[senders[i]] == maxCount && senders[i] > ans) {
                ans = senders[i], maxCount = m[senders[i]];
            };
        };
        return ans;
    };
};