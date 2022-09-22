class Solution {
public:
    string replaceWords(vector<string> &dictionary, string &sentence) {
        unordered_map<string, char> m;
        for (auto &str : dictionary) m[str] = ' ';
        
        int n = sentence.size(), i = 0;
        string ans = "", temp = "";
        while (i < n) {
            temp += sentence[i];
            if (m.find(temp) != m.end()) {
                
                ans += m.find(temp)->first, temp = "";
                while (i < n && sentence[i] != ' ') i++;
                if (i < n) ans += " ";
                
            } else if (sentence[i] == ' ' || i == n - 1)  ans += temp, temp = "";
            i++;
        };        
        return ans;        
    };
};