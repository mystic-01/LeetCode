class Solution {
public:
    string replaceWords(vector<string> &dictionary, string &sentence) {
        unordered_set<string> s;
        for (auto &str : dictionary) s.insert(str);
        
        int n = sentence.size(), i = 0;
        string ans = "", temp = "";
        while (i < n) {
            temp += sentence[i];
            if (s.find(temp) != s.end()) {
                
                ans += *s.find(temp), temp = "";
                while (i < n && sentence[i] != ' ') i++;
                if (i < n) ans += " ";
                
            } else if (sentence[i] == ' ' || i == n - 1)  ans += temp, temp = "";
            i++;
        };        
        return ans;        
    };
};