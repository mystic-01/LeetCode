class Solution {
private:
    bool isSubstr(string &str, string &sub) {
        int i = 0;        
        while (i < str.size() && i < sub.size() && str[i] == sub[i]) i++;
        return i == sub.size();
    };
    
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto &word : words) count += (isSubstr(s, word));
        return count;
    };
};