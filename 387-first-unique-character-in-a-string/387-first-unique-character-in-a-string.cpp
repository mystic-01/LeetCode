class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length(), v[26][2] = {{0, INT_MAX}}, ans = INT_MAX;
        
        for (auto i = 0; i < n; i++) 
            if (v[s[i] - 'a'][0]++ == 0) v[s[i] - 'a'][1] = i; 
        
        for (auto i = 0; i < 26; i++) 
            if (v[i][0] == 1) ans = min(ans, v[i][1]);
        
        return ans == INT_MAX ? -1 : ans;
    };
};

// class Solution {
// public:
//     int firstUniqChar(string s) {
//         queue<int> q;
//         int v[26] = {0}, n = s.length();
//         for (auto i = 0; i < n; i++) {
//             v[s[i] - 'a']++;
//             q.push(i);
//             while (!q.empty() && v[s[q.front()] - 'a'] > 1) q.pop();
//         };
//         return q.empty() ? -1 : q.front();
//     };
// };