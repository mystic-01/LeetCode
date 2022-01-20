class Solution {
public:
    void reverseString(vector<char>& s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        int i = 0, j = s.size() - 1;
        while (i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        };        
    };
};