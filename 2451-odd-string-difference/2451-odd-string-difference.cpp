class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        for (int i = 1; i < n; ++i) {
            int val1 = 2147483647, val2 = 2147483647;
            string str1 = "", str2 = ""; 
            bool isVal1Final = false;
            for (string &str : words) {
                int val = int(str[i] - str[i - 1]);
                if (str1 == "") val1 = val, str1 = str;
                else {
                    if (str2 != "") {
                        if (val == val1) return str2;
                        else return str1;
                    } else {
                        if (isVal1Final) {
                            if (val != val1) return str;                                                    
                        } else {
                            if (val != val1) val2 = val, str2 = str;
                            else isVal1Final = true;    
                        };
                    };
                };
            };
        };
        return "";
    };
};