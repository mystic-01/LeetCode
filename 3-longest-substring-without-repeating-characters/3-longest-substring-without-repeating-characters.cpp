// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         std::ios::sync_with_stdio(false);
//         std::cin.tie(nullptr);        
        
//         int n = s.length(), best = 0, count = 0, i = 0;
//         unordered_map<char, int> m;
        
//         for (auto j = 0; j < n; j++) {
//             m[s[j]]++;
//             if (m.find(s[j])->second >= 2) {
//                 best = max(best, count);
//                 while (i < n && s[i] != s[j]) m[s[i++]]--;
//                 m[s[i++]]--;
//                 count = j - i;
//             };
//             count++;
//         };  
//         best = max(best, count);
//         return best;
//     };
// };

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);        
        
        int n = s.length(), best = 0, left = 0;
        unordered_map<char, int> m;
        
        for (auto right = 0; right < n; right++) {
            if (m.find(s[right]) != m.end()) left = max(m[s[right]] + 1, left);
            best = max(best, right - left + 1);
            m[s[right]] = right;
        };
        return best;
    };
};
