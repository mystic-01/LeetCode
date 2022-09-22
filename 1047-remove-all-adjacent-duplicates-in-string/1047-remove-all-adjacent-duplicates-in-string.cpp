class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int i = 0;
        while (i < s.length()) {
            if (ans.length() && s[i] == ans.back()) ans.pop_back();
            else ans.push_back(s[i]);
            i++;  
        }; 
        return ans;
    };
};