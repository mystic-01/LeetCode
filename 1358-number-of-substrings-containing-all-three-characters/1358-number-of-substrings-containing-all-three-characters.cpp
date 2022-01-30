class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length(), left = 0,count = 0;
        int v[3] = {0, 0, 0};
        for (auto i = 0; i < n; i++) {
            v[s[i] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                count += (n - i);
                v[s[left++] - 'a']--;
            };
        };
        return count;
    };
};