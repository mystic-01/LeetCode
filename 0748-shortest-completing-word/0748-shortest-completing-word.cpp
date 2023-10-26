class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> freq(26, 0), chars;
        string ans = "";
        for (char &ch : licensePlate) {
            if (isalpha(ch)) {
                ++freq[tolower(ch) - 'a'];    
            };
        };
        for (string &str : words) {
            chars = freq;
            for (char &ch2 : str) {
                --chars[ch2 - 'a'];                
            };
            bool foundAllChars = true;
            for (int &x : chars) {
                if (x > 0) {
                    foundAllChars = false;
                    break;
                };
            };
            if (foundAllChars && (ans == "" || str.size() < ans.size())) {
                ans = str;    
            };
        };
        return ans;;
    };
};