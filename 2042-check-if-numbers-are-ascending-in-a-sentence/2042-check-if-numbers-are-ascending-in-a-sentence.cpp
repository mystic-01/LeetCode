class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length(), numToBeat = -1;
        string word = "";
        for (auto i = 0; i < n; i++) {
            if (s[i] != ' ') word += s[i];
            
            if (s[i] == ' ' || i == n - 1) {
            
                int firstCharValue = word[0] - '0';  
                if (firstCharValue >= 0 && firstCharValue <= 9) {
                    int num = stoi(word);
                    if (num <= numToBeat) return false;
                    else numToBeat = num;
                };
                word = "";
            };
        };
        return true;
    };
};