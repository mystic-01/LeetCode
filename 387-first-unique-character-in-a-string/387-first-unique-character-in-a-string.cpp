// class Solution {
// public:
//     int firstUniqChar(string s) {
//         std::ios::sync_with_stdio(false);
//         std::cin.tie(nullptr);     
//         vector<int> v(26);
//         for (auto i : s) v[i - 'a']++;
//         for (auto i = 0; i < s.length(); i++) if (v[s[i] - 'a'] == 1) return i;
//         return -1;
//     };
// };

class Solution {
public:
    int firstUniqChar(string s) {
        queue<int> q;
        int v[26] = {0}, n = s.length();
        for (auto i = 0; i < n; i++) {
            v[s[i] - 'a']++;
            q.push(i);
            while (!q.empty() && v[s[q.front()] - 'a'] > 1) q.pop();
        };
        return q.empty() ? -1 : q.front();
    };
};