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


// ---> Slower when done using map.

// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int n = s.size(), count = 0, left = 0;
//         unordered_map<char, int> m;
//         for (auto i = 0; i < s.length(); i++) {
//             m[s[i]]++;
//             while (m['a'] > 0 && m['b'] > 0 && m['c'] > 0) {
//                 count += (n - i);
//                 m[s[left++]]--;
//             };
//         };
//         return count;
//     };
// };