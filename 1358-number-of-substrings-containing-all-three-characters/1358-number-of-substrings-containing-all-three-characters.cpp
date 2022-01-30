class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count = 0, left = 0;
        vector<int> v(3);
        for (auto i = 0; i < s.length(); i++) {
            v[s[i] - 'a']++;
            while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
                count += (n - i);
                v[s[left++] - 'a']--;
            };
        };
        return count;
    };
};