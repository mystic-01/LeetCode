class Solution {
public:
    string toLowerCase(string s) {
      for (int i = 0; i < s.length(); i++) {
          if (int(s[i]) < 91 && int(s[i]) > 64) s[i] += 32;
      };  
        return s;
    };
};