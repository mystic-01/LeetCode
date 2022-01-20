class Solution {
public:
    string reverseVowels(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int i = 0, j = s.length() - 1;
        vector<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while (i < j) {
            while (i < j && find(v.begin(), v.end(), s[i]) == v.end()) i++;
            while (i < j && find(v.begin(), v.end(), s[j]) == v.end()) j--;
            swap(s[i++], s[j--]);
        };
        return s;
    };
};