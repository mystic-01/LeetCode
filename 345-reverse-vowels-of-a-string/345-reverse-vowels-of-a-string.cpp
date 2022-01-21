class Solution {
public:
    bool isVowel (char x) {
      return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' 
          || x == 'O' || x == 'U';
    };
    
    string reverseVowels(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int i = 0, j = s.length() - 1;
        vector<char> v = {};
        while (i < j) {
            while (i < j && !isVowel(s[i])) i++;
            while (i < j && !isVowel(s[j])) j--;
            swap(s[i++], s[j--]);
        };
        return s;
    };
};