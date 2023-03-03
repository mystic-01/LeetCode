class Solution {
public:
    int strStr(string haystack, string needle) {
        int h = haystack.size(), n = needle.size();
        for (auto i = 0; i < h; i++) if (haystack.substr(i, n) == needle) return i;    
        return -1;
    };
};