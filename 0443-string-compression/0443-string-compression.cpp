class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), lo = 0, hi = 1, toBeMod = 0, count = 1;
        
        while (lo < n) {
            char curr = chars[lo];
            if (hi < n && chars[lo] == chars[hi]) {     
                while (hi < n && chars[lo] == chars[hi]) lo++, hi++, count++;
                
                chars[toBeMod++] = curr;
                                
                for (auto &c : to_string(count)) chars[toBeMod++] = c;
            } else chars[toBeMod++] = curr;
            
            lo++, hi++, count = 1;     
        };
        chars.resize(toBeMod);
        return chars.size();
    };
};