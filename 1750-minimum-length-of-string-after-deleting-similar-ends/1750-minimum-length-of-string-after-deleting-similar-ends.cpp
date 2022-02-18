class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), start = 0, end = n - 1;
        
        while (start < end && s[start] == s[end]) {
            char target = s[start];
            while (start < n && s[start] == target) start++;
            while (end > -1 && s[end] == target) end--;
        };
        
        return max(0, end - start + 1);
    };
};
